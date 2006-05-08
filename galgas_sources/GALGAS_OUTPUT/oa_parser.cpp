//---------------------------------------------------------------------------*
//                                                                           *
//                           File 'oa_parser.cpp'                            *
//         Generated by version GALGAS_BETA_VERSION (LL(1) grammar)          *
//                      april 30th, 2006, at 16h51'30"                       *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#include "utilities/MF_MemoryControl.h"
#include "files/C_TextFileWrite.h"
#include "oa_parser.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  static const char gGGSsourceFile [] = "oa_parser.ggs" ;
  #define SOURCE_FILE_AT_LINE(line) , gGGSsourceFile, line
#else
  #define SOURCE_FILE_AT_LINE(line) 
#endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                Implementation of production rule 'axiome'                 *
//                                                                           *
//---------------------------------------------------------------------------*

void oa_parser::
oa_parser::
pr_axiome_oa_parser_171_14_ (oa_scanner & _inLexique) {
  GGS_M_processor  var_cas_outProcessorMap ;
  var_cas_outProcessorMap = GGS_M_processor::constructor_emptyMap (_inLexique COMMA_HERE) ;
  GGS_M_network  var_cas_outNetworkMap ;
  var_cas_outNetworkMap = GGS_M_network::constructor_emptyMap (_inLexique COMMA_HERE) ;
  GGS_M_messages  var_cas_outMessagesMap ;
  var_cas_outMessagesMap = GGS_M_messages::constructor_emptyMap (_inLexique COMMA_HERE) ;
  GGS_M_tasks  var_cas_outTaskMap ;
  var_cas_outTaskMap = GGS_M_tasks::constructor_emptyMap (_inLexique COMMA_HERE) ;
  _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_system) ;
  { bool syntaxRepeat = true ;
    while (syntaxRepeat) {
      switch (select_repeat_oa_parser_0 (_inLexique)) {
        case 2 : {
          _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_processor) ;
          GGS_lstring  var_cas_processorName ;
          _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_identifier) ;
          var_cas_processorName.defineAttribute (_inLexique.identifierString, _inLexique) ;
          GGS_luint  var_cas_step ;
          switch (select_oa_parser_1 (_inLexique)) {
            case 1 : {
              var_cas_step = GGS_luint::constructor_new (_inLexique, GGS_uint (true, 1UL), GGS_location (_inLexique) COMMA_HERE) ;
              } break ;
            case 2 : {
              _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_scalingfactor) ;
              _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_literal_5Finteger) ;
              var_cas_step.defineAttribute (_inLexique.ulongValue, _inLexique) ;
              if (((var_cas_step.reader_value (_inLexique SOURCE_FILE_AT_LINE (189))) == (GGS_uint (true, 0UL))).isBuiltAndTrue ()) {
                  var_cas_step.reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "the step value must be > 0") SOURCE_FILE_AT_LINE (190)) ;
              }
              } break ;
            default :
              break ;
          }
          var_cas_outProcessorMap.method_insertKey (_inLexique, var_cas_processorName, var_cas_step SOURCE_FILE_AT_LINE (193)) ;
          _inLexique.acceptTerminal (oa_scanner::oa_scanner_1__3B) ;
          } break ;
        case 3 : {
          GGS_bool var_cas_network ;
          switch (select_oa_parser_2 (_inLexique)) {
            case 1 : {
              _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_can) ;
              var_cas_network = GGS_bool (true, true) ;
              } break ;
            case 2 : {
              _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_van) ;
              var_cas_network = GGS_bool (true, false) ;
              } break ;
            default :
              break ;
          }
          _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_network) ;
          GGS_lstring  var_cas_networkName ;
          _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_identifier) ;
          var_cas_networkName.defineAttribute (_inLexique.identifierString, _inLexique) ;
          GGS_luint  var_cas_factor ;
          switch (select_oa_parser_3 (_inLexique)) {
            case 1 : {
              var_cas_factor = GGS_luint::constructor_new (_inLexique, GGS_uint (true, 1UL), GGS_location (_inLexique) COMMA_HERE) ;
              } break ;
            case 2 : {
              _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_scalingfactor) ;
              _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_literal_5Finteger) ;
              var_cas_factor.defineAttribute (_inLexique.ulongValue, _inLexique) ;
              if (((var_cas_factor.reader_value (_inLexique SOURCE_FILE_AT_LINE (213))) == (GGS_uint (true, 0UL))).isBuiltAndTrue ()) {
                  var_cas_factor.reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "the factor value must be > 0") SOURCE_FILE_AT_LINE (214)) ;
              }
              } break ;
            default :
              break ;
          }
          var_cas_outNetworkMap.method_insertKey (_inLexique, var_cas_networkName, var_cas_network, var_cas_factor SOURCE_FILE_AT_LINE (217)) ;
          _inLexique.acceptTerminal (oa_scanner::oa_scanner_1__3B) ;
          } break ;
        case 4 : {
          _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_task) ;
          GGS_lstring  var_cas_taskName ;
          _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_identifier) ;
          var_cas_taskName.defineAttribute (_inLexique.identifierString, _inLexique) ;
          _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_priority) ;
          GGS_luint  var_cas_taskPriority ;
          _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_literal_5Finteger) ;
          var_cas_taskPriority.defineAttribute (_inLexique.ulongValue, _inLexique) ;
          _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_duration) ;
          GGS_luint  var_cas_taskDurationMin ;
          _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_literal_5Finteger) ;
          var_cas_taskDurationMin.defineAttribute (_inLexique.ulongValue, _inLexique) ;
          _inLexique.acceptTerminal (oa_scanner::oa_scanner_1__2E_2E) ;
          GGS_luint  var_cas_taskDurationMax ;
          _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_literal_5Finteger) ;
          var_cas_taskDurationMax.defineAttribute (_inLexique.ulongValue, _inLexique) ;
          GGS_luint  var_cas_taskOffset ;
          GGS_bool var_cas_explicitOffset ;
          switch (select_oa_parser_4 (_inLexique)) {
            case 1 : {
              _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_offset) ;
              _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_literal_5Finteger) ;
              var_cas_taskOffset.defineAttribute (_inLexique.ulongValue, _inLexique) ;
              var_cas_explicitOffset = GGS_bool (true, true) ;
              } break ;
            case 2 : {
              var_cas_taskOffset = GGS_luint::constructor_new (_inLexique, GGS_uint (true, 0UL), GGS_location (_inLexique) COMMA_HERE) ;
              var_cas_explicitOffset = GGS_bool (true, false) ;
              } break ;
            default :
              break ;
          }
          GGS_luint  var_cas_taskDeadline ;
          switch (select_oa_parser_5 (_inLexique)) {
            case 1 : {
              _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_deadline) ;
              _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_literal_5Finteger) ;
              var_cas_taskDeadline.defineAttribute (_inLexique.ulongValue, _inLexique) ;
              } break ;
            case 2 : {
              var_cas_taskDeadline = GGS_luint::constructor_new (_inLexique, GGS_uint (true, 4294967295UL), GGS_location (_inLexique) COMMA_HERE) ;
              } break ;
            default :
              break ;
          }
          GGS_AC_task  var_cas_taskKind ;
          GGS_luint  var_cas_taskProcessorIndex ;
          GGS_luint  var_cas_taskPeriod ;
          switch (select_oa_parser_6 (_inLexique)) {
            case 1 : {
              _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_period) ;
              _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_literal_5Finteger) ;
              var_cas_taskPeriod.defineAttribute (_inLexique.ulongValue, _inLexique) ;
              _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_processor) ;
              GGS_lstring  var_cas_taskProcessorName ;
              _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_identifier) ;
              var_cas_taskProcessorName.defineAttribute (_inLexique.identifierString, _inLexique) ;
              GGS_luint  var_cas_7655 ;
              if (var_cas_outProcessorMap.isBuilt ()) {
                var_cas_outProcessorMap (HERE)->method_searchKeyGetIndex (_inLexique, var_cas_taskProcessorName, var_cas_taskProcessorIndex, var_cas_7655 SOURCE_FILE_AT_LINE (258)) ;
              }
              var_cas_taskKind = GGS_C_independantTask::constructor_new (_inLexique COMMA_HERE) ;
              } break ;
            case 2 : {
              _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_on) ;
              if ((var_cas_explicitOffset).isBuiltAndTrue ()) {
                  GGS_location (_inLexique).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "A dependant task cannot have an offset") SOURCE_FILE_AT_LINE (263)) ;
              }
              switch (select_oa_parser_7 (_inLexique)) {
                case 1 : {
                  _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_task) ;
                  GGS_lstring  var_cas_masterTaskName ;
                  _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_identifier) ;
                  var_cas_masterTaskName.defineAttribute (_inLexique.identifierString, _inLexique) ;
                  GGS_luint  var_cas_every ;
                  switch (select_oa_parser_8 (_inLexique)) {
                    case 1 : {
                      var_cas_every = GGS_luint::constructor_new (_inLexique, GGS_uint (true, 1UL), GGS_location (_inLexique) COMMA_HERE) ;
                      } break ;
                    case 2 : {
                      _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_every) ;
                      _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_literal_5Finteger) ;
                      var_cas_every.defineAttribute (_inLexique.ulongValue, _inLexique) ;
                      } break ;
                    default :
                      break ;
                  }
                  GGS_luint  var_cas_masterTaskIndex ;
                  GGS_luint  var_cas_8213 ;
                  GGS_luint  var_cas_8216 ;
                  GGS_luint  var_cas_8219 ;
                  GGS_luint  var_cas_8222 ;
                  GGS_luint  var_cas_8225 ;
                  GGS_AC_task  var_cas_8260 ;
                  if (var_cas_outTaskMap.isBuilt ()) {
                    var_cas_outTaskMap (HERE)->method_searchKeyGetIndex (_inLexique, var_cas_masterTaskName, var_cas_masterTaskIndex, var_cas_8213, var_cas_8216, var_cas_8219, var_cas_8222, var_cas_8225, var_cas_taskProcessorIndex, var_cas_taskPeriod, var_cas_8260 SOURCE_FILE_AT_LINE (277)) ;
                  }
                  var_cas_taskKind = GGS_C_taskDependsFromTask::constructor_new (_inLexique, var_cas_masterTaskIndex, var_cas_every COMMA_HERE) ;
                  } break ;
                case 2 : {
                  _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_message) ;
                  GGS_lstring  var_cas_masterMessageName ;
                  _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_identifier) ;
                  var_cas_masterMessageName.defineAttribute (_inLexique.identifierString, _inLexique) ;
                  GGS_luint  var_cas_masterMessageIndex ;
                  GGS_luint  var_cas_8567 ;
                  GGS_luint  var_cas_8570 ;
                  GGS_luint  var_cas_8573 ;
                  GGS_luint  var_cas_8576 ;
                  GGS_luint  var_cas_8579 ;
                  GGS_luint  var_cas_8582 ;
                  GGS_AC_canMessage  var_cas_8597 ;
                  if (var_cas_outMessagesMap.isBuilt ()) {
                    var_cas_outMessagesMap (HERE)->method_searchKeyGetIndex (_inLexique, var_cas_masterMessageName, var_cas_masterMessageIndex, var_cas_8567, var_cas_8570, var_cas_8573, var_cas_8576, var_cas_8579, var_cas_8582, var_cas_taskPeriod, var_cas_8597 SOURCE_FILE_AT_LINE (284)) ;
                  }
                  _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_processor) ;
                  GGS_lstring  var_cas_taskProcessorName ;
                  _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_identifier) ;
                  var_cas_taskProcessorName.defineAttribute (_inLexique.identifierString, _inLexique) ;
                  GGS_luint  var_cas_every ;
                  switch (select_oa_parser_9 (_inLexique)) {
                    case 1 : {
                      var_cas_every = GGS_luint::constructor_new (_inLexique, GGS_uint (true, 1UL), GGS_location (_inLexique) COMMA_HERE) ;
                      } break ;
                    case 2 : {
                      _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_every) ;
                      _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_literal_5Finteger) ;
                      var_cas_every.defineAttribute (_inLexique.ulongValue, _inLexique) ;
                      } break ;
                    default :
                      break ;
                  }
                  GGS_luint  var_cas_8958 ;
                  if (var_cas_outProcessorMap.isBuilt ()) {
                    var_cas_outProcessorMap (HERE)->method_searchKeyGetIndex (_inLexique, var_cas_taskProcessorName, var_cas_taskProcessorIndex, var_cas_8958 SOURCE_FILE_AT_LINE (295)) ;
                  }
                  var_cas_taskKind = GGS_C_taskDependsFromMessage::constructor_new (_inLexique, var_cas_masterMessageIndex, var_cas_every COMMA_HERE) ;
                  } break ;
                default :
                  break ;
              }
              } break ;
            default :
              break ;
          }
          var_cas_outTaskMap.method_insertKey (_inLexique, var_cas_taskName, var_cas_taskPriority, var_cas_taskOffset, var_cas_taskDeadline, var_cas_taskDurationMin, var_cas_taskDurationMax, var_cas_taskProcessorIndex, var_cas_taskPeriod, var_cas_taskKind SOURCE_FILE_AT_LINE (299)) ;
          _inLexique.acceptTerminal (oa_scanner::oa_scanner_1__3B) ;
          } break ;
        case 5 : {
          GGS_luint  var_cas_messageClass ;
          switch (select_oa_parser_10 (_inLexique)) {
            case 1 : {
              _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_standard) ;
              var_cas_messageClass = GGS_luint::constructor_new (_inLexique, GGS_uint (true, 0UL), GGS_location (_inLexique) COMMA_HERE) ;
              _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_message) ;
              } break ;
            case 2 : {
              _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_extended) ;
              var_cas_messageClass = GGS_luint::constructor_new (_inLexique, GGS_uint (true, 1UL), GGS_location (_inLexique) COMMA_HERE) ;
              _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_message) ;
              } break ;
            case 3 : {
              _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_message) ;
              var_cas_messageClass = GGS_luint::constructor_new (_inLexique, GGS_uint (true, 2UL), GGS_location (_inLexique) COMMA_HERE) ;
              } break ;
            default :
              break ;
          }
          GGS_lstring  var_cas_messageName ;
          _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_identifier) ;
          var_cas_messageName.defineAttribute (_inLexique.identifierString, _inLexique) ;
          _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_network) ;
          GGS_lstring  var_cas_networkName ;
          _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_identifier) ;
          var_cas_networkName.defineAttribute (_inLexique.identifierString, _inLexique) ;
          GGS_luint  var_cas_networkIndex ;
          GGS_bool var_cas_CANnetwork ;
          GGS_luint  var_cas_10095 ;
          if (var_cas_outNetworkMap.isBuilt ()) {
            var_cas_outNetworkMap (HERE)->method_searchKeyGetIndex (_inLexique, var_cas_networkName, var_cas_networkIndex, var_cas_CANnetwork, var_cas_10095 SOURCE_FILE_AT_LINE (329)) ;
          }
          if ((((var_cas_CANnetwork) && ((var_cas_messageClass.reader_value (_inLexique SOURCE_FILE_AT_LINE (330))) == (GGS_uint (true, 2UL))))).isBuiltAndTrue ()) {
              var_cas_messageClass.reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "a CAN message must be either standard either extended") SOURCE_FILE_AT_LINE (331)) ;
          }else if (((((! (var_cas_CANnetwork))) && ((var_cas_messageClass.reader_value (_inLexique SOURCE_FILE_AT_LINE (332))) != (GGS_uint (true, 2UL))))).isBuiltAndTrue ()) {
              var_cas_messageClass.reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "a VAN message cannot be standard or extended") SOURCE_FILE_AT_LINE (333)) ;
          }
          _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_length) ;
          GGS_luint  var_cas_bytesCount ;
          _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_literal_5Finteger) ;
          var_cas_bytesCount.defineAttribute (_inLexique.ulongValue, _inLexique) ;
          if ((((var_cas_CANnetwork) && ((var_cas_bytesCount.reader_value (_inLexique SOURCE_FILE_AT_LINE (338))) > (GGS_uint (true, 8UL))))).isBuiltAndTrue ()) {
              var_cas_bytesCount.reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "CAN message length must be <= 8 bytes") SOURCE_FILE_AT_LINE (339)) ;
          }else if (((((! (var_cas_CANnetwork))) && ((var_cas_bytesCount.reader_value (_inLexique SOURCE_FILE_AT_LINE (340))) > (GGS_uint (true, 28UL))))).isBuiltAndTrue ()) {
              var_cas_bytesCount.reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "VAN message must be <= 28 bytes") SOURCE_FILE_AT_LINE (341)) ;
          }
          _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_priority) ;
          GGS_luint  var_cas_priority ;
          _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_literal_5Finteger) ;
          var_cas_priority.defineAttribute (_inLexique.ulongValue, _inLexique) ;
          GGS_luint  var_cas_offset ;
          GGS_bool var_cas_explicitOffset ;
          switch (select_oa_parser_11 (_inLexique)) {
            case 1 : {
              _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_offset) ;
              _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_literal_5Finteger) ;
              var_cas_offset.defineAttribute (_inLexique.ulongValue, _inLexique) ;
              var_cas_explicitOffset = GGS_bool (true, true) ;
              } break ;
            case 2 : {
              var_cas_offset = GGS_luint::constructor_new (_inLexique, GGS_uint (true, 0UL), GGS_location (_inLexique) COMMA_HERE) ;
              var_cas_explicitOffset = GGS_bool (true, false) ;
              } break ;
            default :
              break ;
          }
          GGS_luint  var_cas_deadline ;
          switch (select_oa_parser_12 (_inLexique)) {
            case 1 : {
              _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_deadline) ;
              _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_literal_5Finteger) ;
              var_cas_deadline.defineAttribute (_inLexique.ulongValue, _inLexique) ;
              } break ;
            case 2 : {
              var_cas_deadline = GGS_luint::constructor_new (_inLexique, GGS_uint (true, 4294967295UL), GGS_location (_inLexique) COMMA_HERE) ;
              } break ;
            default :
              break ;
          }
          GGS_AC_canMessage  var_cas_messageKind ;
          GGS_luint  var_cas_period ;
          switch (select_oa_parser_13 (_inLexique)) {
            case 1 : {
              _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_period) ;
              _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_literal_5Finteger) ;
              var_cas_period.defineAttribute (_inLexique.ulongValue, _inLexique) ;
              var_cas_messageKind = GGS_C_canIndependantMessage::constructor_new (_inLexique COMMA_HERE) ;
              } break ;
            case 2 : {
              _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_on) ;
              if ((var_cas_explicitOffset).isBuiltAndTrue ()) {
                  GGS_location (_inLexique).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "A dependant task cannot have an offset") SOURCE_FILE_AT_LINE (372)) ;
              }
              switch (select_oa_parser_14 (_inLexique)) {
                case 1 : {
                  _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_message) ;
                  GGS_lstring  var_cas_name ;
                  _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_identifier) ;
                  var_cas_name.defineAttribute (_inLexique.identifierString, _inLexique) ;
                  GGS_luint  var_cas_messageIndex ;
                  GGS_luint  var_cas_11669 ;
                  GGS_luint  var_cas_11672 ;
                  GGS_luint  var_cas_11675 ;
                  GGS_luint  var_cas_11678 ;
                  GGS_luint  var_cas_11681 ;
                  GGS_luint  var_cas_11684 ;
                  GGS_AC_canMessage  var_cas_11695 ;
                  if (var_cas_outMessagesMap.isBuilt ()) {
                    var_cas_outMessagesMap (HERE)->method_searchKeyGetIndex (_inLexique, var_cas_name, var_cas_messageIndex, var_cas_11669, var_cas_11672, var_cas_11675, var_cas_11678, var_cas_11681, var_cas_11684, var_cas_period, var_cas_11695 SOURCE_FILE_AT_LINE (379)) ;
                  }
                  var_cas_messageKind = GGS_C_canMessageFromMessage::constructor_new (_inLexique, var_cas_messageIndex COMMA_HERE) ;
                  } break ;
                case 2 : {
                  _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_task) ;
                  GGS_lstring  var_cas_taskName ;
                  _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_identifier) ;
                  var_cas_taskName.defineAttribute (_inLexique.identifierString, _inLexique) ;
                  GGS_luint  var_cas_taskIndex ;
                  GGS_luint  var_cas_11945 ;
                  GGS_luint  var_cas_11948 ;
                  GGS_luint  var_cas_11951 ;
                  GGS_luint  var_cas_11954 ;
                  GGS_luint  var_cas_11957 ;
                  GGS_luint  var_cas_11960 ;
                  GGS_AC_task  var_cas_11971 ;
                  if (var_cas_outTaskMap.isBuilt ()) {
                    var_cas_outTaskMap (HERE)->method_searchKeyGetIndex (_inLexique, var_cas_taskName, var_cas_taskIndex, var_cas_11945, var_cas_11948, var_cas_11951, var_cas_11954, var_cas_11957, var_cas_11960, var_cas_period, var_cas_11971 SOURCE_FILE_AT_LINE (386)) ;
                  }
                  var_cas_messageKind = GGS_C_canMessageFromTask::constructor_new (_inLexique, var_cas_taskIndex COMMA_HERE) ;
                  } break ;
                default :
                  break ;
              }
              } break ;
            default :
              break ;
          }
          var_cas_outMessagesMap.method_insertKey (_inLexique, var_cas_messageName, var_cas_messageClass, var_cas_networkIndex, var_cas_bytesCount, var_cas_priority, var_cas_offset, var_cas_deadline, var_cas_period, var_cas_messageKind SOURCE_FILE_AT_LINE (390)) ;
          _inLexique.acceptTerminal (oa_scanner::oa_scanner_1__3B) ;
          } break ;
        default :
          syntaxRepeat = false ;
          break ;
      }
    }
  }
  _inLexique.acceptTerminal (oa_scanner::oa_scanner_1_end) ;
  if (var_cas_outProcessorMap.isBuilt () &&
      var_cas_outNetworkMap.isBuilt () &&
      var_cas_outMessagesMap.isBuilt () &&
      var_cas_outTaskMap.isBuilt ()) {
    ::routine_performComputations (_inLexique,  var_cas_outProcessorMap,  var_cas_outNetworkMap,  var_cas_outMessagesMap,  var_cas_outTaskMap SOURCE_FILE_AT_LINE (396)) ;
  }
}

//---------------------------------------------------------------------------*

