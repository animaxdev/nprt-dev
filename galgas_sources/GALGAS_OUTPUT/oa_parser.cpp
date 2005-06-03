//---------------------------------------------------------------------------*
//                                                                           *
//                           File 'oa_parser.cpp'                            *
//               Generated by version 0.14.1 (LL(1) grammar)                 *
//                       june 3rd, 2005, at 13h10'30"                        *
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

#include "memory/M_memory_control.h"
#include "files/C_text_file_write.h"
#include "oa_parser.h"


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                Implementation of production rule 'axiome'                 *
//                                                                           *
//---------------------------------------------------------------------------*

void oa_parser::
pr_axiome_oa_parser_175_14_ (oa_scanner & lexique_var_) {
  GGS_M_processor  var_cas_outProcessorMap ;
  var_cas_outProcessorMap = GGS_M_processor::constructor_empty () ;
  GGS_M_network  var_cas_outNetworkMap ;
  var_cas_outNetworkMap = GGS_M_network::constructor_empty () ;
  GGS_M_messages  var_cas_outMessagesMap ;
  var_cas_outMessagesMap = GGS_M_messages::constructor_empty () ;
  GGS_M_tasks  var_cas_outTaskMap ;
  var_cas_outTaskMap = GGS_M_tasks::constructor_empty () ;
  lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_system) ;
  { bool syntaxRepeat = true ;
    while (syntaxRepeat) {
      switch (select_repeat_oa_parser_0 (lexique_var_)) {
        case 2 : {
          lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_processor) ;
          GGS_lstring  var_cas_processorName ;
          lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_identifier) ;
          var_cas_processorName.defineAttribute (lexique_var_.identifierString, lexique_var_) ;
          GGS_luint  var_cas_step ;
          switch (select_oa_parser_1 (lexique_var_)) {
            case 1 : {
              var_cas_step = GGS_luint::constructor_new (GGS_uint (true, 1UL), GGS_location (lexique_var_)) ;
              } break ;
            case 2 : {
              lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_scalingfactor) ;
              lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_literal_5Finteger) ;
              var_cas_step.defineAttribute (lexique_var_.ulongValue, lexique_var_) ;
              if (((var_cas_step.reader_value ()) == (GGS_uint (true, 0UL))).isBuiltAndTrue ()) {
                  var_cas_step.reader_location ().signalGGSSemanticError (lexique_var_, GGS_string (true, "the step value must be > 0")) ;
              }
              } break ;
            default :
              break ;
          }
          insertKey_M_processor (lexique_var_,
                                          var_cas_outProcessorMap,
                                          var_cas_processorName,
                                          var_cas_step,
                                          NULL) ;
          lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1__3B) ;
          } break ;
        case 3 : {
          GGS_bool var_cas_network ;
          switch (select_oa_parser_2 (lexique_var_)) {
            case 1 : {
              lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_can) ;
              var_cas_network = GGS_bool (true, true) ;
              } break ;
            case 2 : {
              lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_van) ;
              var_cas_network = GGS_bool (true, false) ;
              } break ;
            default :
              break ;
          }
          lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_network) ;
          GGS_lstring  var_cas_networkName ;
          lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_identifier) ;
          var_cas_networkName.defineAttribute (lexique_var_.identifierString, lexique_var_) ;
          GGS_luint  var_cas_factor ;
          switch (select_oa_parser_3 (lexique_var_)) {
            case 1 : {
              var_cas_factor = GGS_luint::constructor_new (GGS_uint (true, 1UL), GGS_location (lexique_var_)) ;
              } break ;
            case 2 : {
              lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_scalingfactor) ;
              lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_literal_5Finteger) ;
              var_cas_factor.defineAttribute (lexique_var_.ulongValue, lexique_var_) ;
              if (((var_cas_factor.reader_value ()) == (GGS_uint (true, 0UL))).isBuiltAndTrue ()) {
                  var_cas_factor.reader_location ().signalGGSSemanticError (lexique_var_, GGS_string (true, "the factor value must be > 0")) ;
              }
              } break ;
            default :
              break ;
          }
          insertKey_M_network (lexique_var_,
                                          var_cas_outNetworkMap,
                                          var_cas_networkName,
                                          var_cas_network,
                                          var_cas_factor,
                                          NULL) ;
          lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1__3B) ;
          } break ;
        case 4 : {
          lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_task) ;
          GGS_lstring  var_cas_taskName ;
          lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_identifier) ;
          var_cas_taskName.defineAttribute (lexique_var_.identifierString, lexique_var_) ;
          lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_priority) ;
          GGS_luint  var_cas_taskPriority ;
          lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_literal_5Finteger) ;
          var_cas_taskPriority.defineAttribute (lexique_var_.ulongValue, lexique_var_) ;
          lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_duration) ;
          GGS_luint  var_cas_taskDurationMin ;
          lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_literal_5Finteger) ;
          var_cas_taskDurationMin.defineAttribute (lexique_var_.ulongValue, lexique_var_) ;
          lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1__2E_2E) ;
          GGS_luint  var_cas_taskDurationMax ;
          lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_literal_5Finteger) ;
          var_cas_taskDurationMax.defineAttribute (lexique_var_.ulongValue, lexique_var_) ;
          GGS_luint  var_cas_taskOffset ;
          GGS_bool var_cas_explicitOffset ;
          switch (select_oa_parser_4 (lexique_var_)) {
            case 1 : {
              lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_offset) ;
              lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_literal_5Finteger) ;
              var_cas_taskOffset.defineAttribute (lexique_var_.ulongValue, lexique_var_) ;
              var_cas_explicitOffset = GGS_bool (true, true) ;
              } break ;
            case 2 : {
              var_cas_taskOffset = GGS_luint::constructor_new (GGS_uint (true, 0UL), GGS_location (lexique_var_)) ;
              var_cas_explicitOffset = GGS_bool (true, false) ;
              } break ;
            default :
              break ;
          }
          GGS_luint  var_cas_taskDeadline ;
          switch (select_oa_parser_5 (lexique_var_)) {
            case 1 : {
              lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_deadline) ;
              lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_literal_5Finteger) ;
              var_cas_taskDeadline.defineAttribute (lexique_var_.ulongValue, lexique_var_) ;
              } break ;
            case 2 : {
              var_cas_taskDeadline = GGS_luint::constructor_new (GGS_uint (true, 4294967295UL), GGS_location (lexique_var_)) ;
              } break ;
            default :
              break ;
          }
          GGS_AC_task  var_cas_taskKind ;
          GGS_luint  var_cas_taskProcessorIndex ;
          GGS_luint  var_cas_taskPeriod ;
          switch (select_oa_parser_6 (lexique_var_)) {
            case 1 : {
              lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_period) ;
              lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_literal_5Finteger) ;
              var_cas_taskPeriod.defineAttribute (lexique_var_.ulongValue, lexique_var_) ;
              lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_processor) ;
              GGS_lstring  var_cas_taskProcessorName ;
              lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_identifier) ;
              var_cas_taskProcessorName.defineAttribute (lexique_var_.identifierString, lexique_var_) ;
              searchKey_M_processor (lexique_var_,
                                              var_cas_outProcessorMap,
                                              var_cas_taskProcessorName,
                                              NULL,
                                              & var_cas_taskProcessorIndex) ;
              var_cas_taskKind = GGS_C_independantTask::constructor_new () ;
              } break ;
            case 2 : {
              lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_on) ;
              if ((var_cas_explicitOffset).isBuiltAndTrue ()) {
                  GGS_location (lexique_var_).reader_location ().signalGGSSemanticError (lexique_var_, GGS_string (true, "A dependant task cannot have an offset")) ;
              }
              switch (select_oa_parser_7 (lexique_var_)) {
                case 1 : {
                  lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_task) ;
                  GGS_lstring  var_cas_masterTaskName ;
                  lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_identifier) ;
                  var_cas_masterTaskName.defineAttribute (lexique_var_.identifierString, lexique_var_) ;
                  GGS_luint  var_cas_every ;
                  switch (select_oa_parser_8 (lexique_var_)) {
                    case 1 : {
                      var_cas_every = GGS_luint::constructor_new (GGS_uint (true, 1UL), GGS_location (lexique_var_)) ;
                      } break ;
                    case 2 : {
                      lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_every) ;
                      lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_literal_5Finteger) ;
                      var_cas_every.defineAttribute (lexique_var_.ulongValue, lexique_var_) ;
                      } break ;
                    default :
                      break ;
                  }
                  GGS_luint  var_cas_masterTaskIndex ;
                  searchKey_M_tasks (lexique_var_,
                                                  var_cas_outTaskMap,
                                                  var_cas_masterTaskName,
                                                  NULL,
                                                  NULL,
                                                  NULL,
                                                  NULL,
                                                  NULL,
                                                  & var_cas_taskProcessorIndex,
                                                  & var_cas_taskPeriod,
                                                  NULL,
                                                  & var_cas_masterTaskIndex) ;
                  var_cas_taskKind = GGS_C_taskDependsFromTask::constructor_new (var_cas_masterTaskIndex, var_cas_every) ;
                  } break ;
                case 2 : {
                  lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_message) ;
                  GGS_lstring  var_cas_masterMessageName ;
                  lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_identifier) ;
                  var_cas_masterMessageName.defineAttribute (lexique_var_.identifierString, lexique_var_) ;
                  GGS_luint  var_cas_masterMessageIndex ;
                  searchKey_M_messages (lexique_var_,
                                                  var_cas_outMessagesMap,
                                                  var_cas_masterMessageName,
                                                  NULL,
                                                  NULL,
                                                  NULL,
                                                  NULL,
                                                  NULL,
                                                  NULL,
                                                  & var_cas_taskPeriod,
                                                  NULL,
                                                  & var_cas_masterMessageIndex) ;
                  lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_processor) ;
                  GGS_lstring  var_cas_taskProcessorName ;
                  lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_identifier) ;
                  var_cas_taskProcessorName.defineAttribute (lexique_var_.identifierString, lexique_var_) ;
                  GGS_luint  var_cas_every ;
                  switch (select_oa_parser_9 (lexique_var_)) {
                    case 1 : {
                      var_cas_every = GGS_luint::constructor_new (GGS_uint (true, 1UL), GGS_location (lexique_var_)) ;
                      } break ;
                    case 2 : {
                      lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_every) ;
                      lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_literal_5Finteger) ;
                      var_cas_every.defineAttribute (lexique_var_.ulongValue, lexique_var_) ;
                      } break ;
                    default :
                      break ;
                  }
                  searchKey_M_processor (lexique_var_,
                                                  var_cas_outProcessorMap,
                                                  var_cas_taskProcessorName,
                                                  NULL,
                                                  & var_cas_taskProcessorIndex) ;
                  var_cas_taskKind = GGS_C_taskDependsFromMessage::constructor_new (var_cas_masterMessageIndex, var_cas_every) ;
                  } break ;
                default :
                  break ;
              }
              } break ;
            default :
              break ;
          }
          insertKey_M_tasks (lexique_var_,
                                          var_cas_outTaskMap,
                                          var_cas_taskName,
                                          var_cas_taskPriority,
                                          var_cas_taskOffset,
                                          var_cas_taskDeadline,
                                          var_cas_taskDurationMin,
                                          var_cas_taskDurationMax,
                                          var_cas_taskProcessorIndex,
                                          var_cas_taskPeriod,
                                          var_cas_taskKind,
                                          NULL) ;
          lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1__3B) ;
          } break ;
        case 5 : {
          GGS_luint  var_cas_messageClass ;
          switch (select_oa_parser_10 (lexique_var_)) {
            case 1 : {
              lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_standard) ;
              var_cas_messageClass = GGS_luint::constructor_new (GGS_uint (true, 0UL), GGS_location (lexique_var_)) ;
              lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_message) ;
              } break ;
            case 2 : {
              lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_extended) ;
              var_cas_messageClass = GGS_luint::constructor_new (GGS_uint (true, 1UL), GGS_location (lexique_var_)) ;
              lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_message) ;
              } break ;
            case 3 : {
              lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_message) ;
              var_cas_messageClass = GGS_luint::constructor_new (GGS_uint (true, 2UL), GGS_location (lexique_var_)) ;
              } break ;
            default :
              break ;
          }
          GGS_lstring  var_cas_messageName ;
          lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_identifier) ;
          var_cas_messageName.defineAttribute (lexique_var_.identifierString, lexique_var_) ;
          lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_network) ;
          GGS_lstring  var_cas_networkName ;
          lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_identifier) ;
          var_cas_networkName.defineAttribute (lexique_var_.identifierString, lexique_var_) ;
          GGS_luint  var_cas_networkIndex ;
          GGS_bool var_cas_CANnetwork ;
          searchKey_M_network (lexique_var_,
                                          var_cas_outNetworkMap,
                                          var_cas_networkName,
                                          & var_cas_CANnetwork,
                                          NULL,
                                          & var_cas_networkIndex) ;
          if ((((var_cas_CANnetwork) && ((var_cas_messageClass.reader_value ()) == (GGS_uint (true, 2UL))))).isBuiltAndTrue ()) {
              var_cas_messageClass.reader_location ().signalGGSSemanticError (lexique_var_, GGS_string (true, "a CAN message must be either standard either extended")) ;
          }else if (((((! var_cas_CANnetwork)) && ((var_cas_messageClass.reader_value ()) != (GGS_uint (true, 2UL))))).isBuiltAndTrue ()) {
              var_cas_messageClass.reader_location ().signalGGSSemanticError (lexique_var_, GGS_string (true, "a VAN message cannot be standard or extended")) ;
          }
          lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_length) ;
          GGS_luint  var_cas_bytesCount ;
          lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_literal_5Finteger) ;
          var_cas_bytesCount.defineAttribute (lexique_var_.ulongValue, lexique_var_) ;
          if ((((var_cas_CANnetwork) && ((var_cas_bytesCount.reader_value ()) > (GGS_uint (true, 8UL))))).isBuiltAndTrue ()) {
              var_cas_bytesCount.reader_location ().signalGGSSemanticError (lexique_var_, GGS_string (true, "CAN message length must be <= 8 bytes")) ;
          }else if (((((! var_cas_CANnetwork)) && ((var_cas_bytesCount.reader_value ()) > (GGS_uint (true, 28UL))))).isBuiltAndTrue ()) {
              var_cas_bytesCount.reader_location ().signalGGSSemanticError (lexique_var_, GGS_string (true, "VAN message must be <= 28 bytes")) ;
          }
          lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_priority) ;
          GGS_luint  var_cas_priority ;
          lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_literal_5Finteger) ;
          var_cas_priority.defineAttribute (lexique_var_.ulongValue, lexique_var_) ;
          GGS_luint  var_cas_offset ;
          GGS_bool var_cas_explicitOffset ;
          switch (select_oa_parser_11 (lexique_var_)) {
            case 1 : {
              lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_offset) ;
              lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_literal_5Finteger) ;
              var_cas_offset.defineAttribute (lexique_var_.ulongValue, lexique_var_) ;
              var_cas_explicitOffset = GGS_bool (true, true) ;
              } break ;
            case 2 : {
              var_cas_offset = GGS_luint::constructor_new (GGS_uint (true, 0UL), GGS_location (lexique_var_)) ;
              var_cas_explicitOffset = GGS_bool (true, false) ;
              } break ;
            default :
              break ;
          }
          GGS_luint  var_cas_deadline ;
          switch (select_oa_parser_12 (lexique_var_)) {
            case 1 : {
              lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_deadline) ;
              lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_literal_5Finteger) ;
              var_cas_deadline.defineAttribute (lexique_var_.ulongValue, lexique_var_) ;
              } break ;
            case 2 : {
              var_cas_deadline = GGS_luint::constructor_new (GGS_uint (true, 4294967295UL), GGS_location (lexique_var_)) ;
              } break ;
            default :
              break ;
          }
          GGS_AC_canMessage  var_cas_messageKind ;
          GGS_luint  var_cas_period ;
          switch (select_oa_parser_13 (lexique_var_)) {
            case 1 : {
              lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_period) ;
              lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_literal_5Finteger) ;
              var_cas_period.defineAttribute (lexique_var_.ulongValue, lexique_var_) ;
              var_cas_messageKind = GGS_C_canIndependantMessage::constructor_new () ;
              } break ;
            case 2 : {
              lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_on) ;
              if ((var_cas_explicitOffset).isBuiltAndTrue ()) {
                  GGS_location (lexique_var_).reader_location ().signalGGSSemanticError (lexique_var_, GGS_string (true, "A dependant task cannot have an offset")) ;
              }
              switch (select_oa_parser_14 (lexique_var_)) {
                case 1 : {
                  lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_message) ;
                  GGS_lstring  var_cas_name ;
                  lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_identifier) ;
                  var_cas_name.defineAttribute (lexique_var_.identifierString, lexique_var_) ;
                  GGS_luint  var_cas_messageIndex ;
                  searchKey_M_messages (lexique_var_,
                                                  var_cas_outMessagesMap,
                                                  var_cas_name,
                                                  NULL,
                                                  NULL,
                                                  NULL,
                                                  NULL,
                                                  NULL,
                                                  NULL,
                                                  & var_cas_period,
                                                  NULL,
                                                  & var_cas_messageIndex) ;
                  var_cas_messageKind = GGS_C_canMessageFromMessage::constructor_new (var_cas_messageIndex) ;
                  } break ;
                case 2 : {
                  lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_task) ;
                  GGS_lstring  var_cas_taskName ;
                  lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_identifier) ;
                  var_cas_taskName.defineAttribute (lexique_var_.identifierString, lexique_var_) ;
                  GGS_luint  var_cas_taskIndex ;
                  searchKey_M_tasks (lexique_var_,
                                                  var_cas_outTaskMap,
                                                  var_cas_taskName,
                                                  NULL,
                                                  NULL,
                                                  NULL,
                                                  NULL,
                                                  NULL,
                                                  NULL,
                                                  & var_cas_period,
                                                  NULL,
                                                  & var_cas_taskIndex) ;
                  var_cas_messageKind = GGS_C_canMessageFromTask::constructor_new (var_cas_taskIndex) ;
                  } break ;
                default :
                  break ;
              }
              } break ;
            default :
              break ;
          }
          insertKey_M_messages (lexique_var_,
                                          var_cas_outMessagesMap,
                                          var_cas_messageName,
                                          var_cas_messageClass,
                                          var_cas_networkIndex,
                                          var_cas_bytesCount,
                                          var_cas_priority,
                                          var_cas_offset,
                                          var_cas_deadline,
                                          var_cas_period,
                                          var_cas_messageKind,
                                          NULL) ;
          lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1__3B) ;
          } break ;
        default :
          syntaxRepeat = false ;
          break ;
      }
    }
  }
  lexique_var_.acceptTerminal (oa_scanner::oa_scanner_1_end) ;
  if (var_cas_outProcessorMap.isBuilt () &&
      var_cas_outNetworkMap.isBuilt () &&
      var_cas_outMessagesMap.isBuilt () &&
      var_cas_outTaskMap.isBuilt ()) {
    ::performComputations (lexique_var_,  var_cas_outProcessorMap,  var_cas_outNetworkMap,  var_cas_outMessagesMap,  var_cas_outTaskMap) ;
  }
}

//---------------------------------------------------------------------------*

