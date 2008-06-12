//---------------------------------------------------------------------------*
//                                                                           *
//                           File 'oa_parser.cpp'                            *
//                 Generated by version GALGAS_BETA_VERSION                  *
//                      june 12th, 2008, at 20h56'45"                        *
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
oa_parser::
pr_axiome_oa_parser_13_4_ (oa_scanner & _inLexique) {
  GGS_M_processor  var_cas_outProcessorMap ;
  var_cas_outProcessorMap = GGS_M_processor ::constructor_emptyMap (_inLexique COMMA_HERE) ;
  GGS_M_network  var_cas_outNetworkMap ;
  var_cas_outNetworkMap = GGS_M_network ::constructor_emptyMap (_inLexique COMMA_HERE) ;
  GGS_M_messages  var_cas_outMessagesMap ;
  var_cas_outMessagesMap = GGS_M_messages ::constructor_emptyMap (_inLexique COMMA_HERE) ;
  GGS_M_tasks  var_cas_outTaskMap ;
  var_cas_outTaskMap = GGS_M_tasks ::constructor_emptyMap (_inLexique COMMA_HERE) ;
  _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_system) COMMA_HERE) ;
  { bool syntaxRepeat_0 = true ;
    while (syntaxRepeat_0) {
      switch (select_repeat_oa_parser_0 (_inLexique)) {
        case 2 : {
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_processor) COMMA_HERE) ;
          GGS_lstring  var_cas_processorName ;
          _inLexique._assignFromAttribute_identifierString (var_cas_processorName) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_identifier) COMMA_HERE) ;
          GGS_luint  var_cas_step ;
          switch (select_oa_parser_1 (_inLexique)) {
            case 1 : {
              var_cas_step = GGS_luint ::constructor_new (_inLexique, GGS_uint (true, 1U), GGS_location (_inLexique) COMMA_HERE) ;
              } break ;
            case 2 : {
              _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_scalingfactor) COMMA_HERE) ;
              _inLexique._assignFromAttribute_ulongValue (var_cas_step) ;
              _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_literal_5Finteger) COMMA_HERE) ;
              if (((var_cas_step.reader_uint (_inLexique COMMA_SOURCE_FILE_AT_LINE (31)))._operator_isEqual (GGS_uint (true, 0U))).isBuiltAndTrue ()) {
                var_cas_step.reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "the step value must be > 0") COMMA_SOURCE_FILE_AT_LINE (32)) ;
              }
              } break ;
            default :
              break ;
          }
          var_cas_outProcessorMap.modifier_insertKey (_inLexique, var_cas_processorName, var_cas_step COMMA_SOURCE_FILE_AT_LINE (35)) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1__3B) COMMA_HERE) ;
          } break ;
        case 3 : {
          GGS_bool var_cas_network ;
          switch (select_oa_parser_2 (_inLexique)) {
            case 1 : {
              _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_can) COMMA_HERE) ;
              var_cas_network = GGS_bool (true, true) ;
              } break ;
            case 2 : {
              _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_van) COMMA_HERE) ;
              var_cas_network = GGS_bool (true, false) ;
              } break ;
            default :
              break ;
          }
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_network) COMMA_HERE) ;
          GGS_lstring  var_cas_networkName ;
          _inLexique._assignFromAttribute_identifierString (var_cas_networkName) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_identifier) COMMA_HERE) ;
          GGS_luint  var_cas_factor ;
          switch (select_oa_parser_3 (_inLexique)) {
            case 1 : {
              var_cas_factor = GGS_luint ::constructor_new (_inLexique, GGS_uint (true, 1U), GGS_location (_inLexique) COMMA_HERE) ;
              } break ;
            case 2 : {
              _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_scalingfactor) COMMA_HERE) ;
              _inLexique._assignFromAttribute_ulongValue (var_cas_factor) ;
              _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_literal_5Finteger) COMMA_HERE) ;
              if (((var_cas_factor.reader_uint (_inLexique COMMA_SOURCE_FILE_AT_LINE (55)))._operator_isEqual (GGS_uint (true, 0U))).isBuiltAndTrue ()) {
                var_cas_factor.reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "the factor value must be > 0") COMMA_SOURCE_FILE_AT_LINE (56)) ;
              }
              } break ;
            default :
              break ;
          }
          var_cas_outNetworkMap.modifier_insertKey (_inLexique, var_cas_networkName, var_cas_network, var_cas_factor COMMA_SOURCE_FILE_AT_LINE (59)) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1__3B) COMMA_HERE) ;
          } break ;
        case 4 : {
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_task) COMMA_HERE) ;
          GGS_lstring  var_cas_taskName ;
          _inLexique._assignFromAttribute_identifierString (var_cas_taskName) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_identifier) COMMA_HERE) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_priority) COMMA_HERE) ;
          GGS_luint  var_cas_taskPriority ;
          _inLexique._assignFromAttribute_ulongValue (var_cas_taskPriority) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_literal_5Finteger) COMMA_HERE) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_duration) COMMA_HERE) ;
          GGS_luint  var_cas_taskDurationMin ;
          _inLexique._assignFromAttribute_ulongValue (var_cas_taskDurationMin) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_literal_5Finteger) COMMA_HERE) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1__2E_2E) COMMA_HERE) ;
          GGS_luint  var_cas_taskDurationMax ;
          _inLexique._assignFromAttribute_ulongValue (var_cas_taskDurationMax) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_literal_5Finteger) COMMA_HERE) ;
          GGS_luint  var_cas_taskOffset ;
          GGS_bool var_cas_explicitOffset ;
          switch (select_oa_parser_4 (_inLexique)) {
            case 1 : {
              _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_offset) COMMA_HERE) ;
              _inLexique._assignFromAttribute_ulongValue (var_cas_taskOffset) ;
              _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_literal_5Finteger) COMMA_HERE) ;
              var_cas_explicitOffset = GGS_bool (true, true) ;
              } break ;
            case 2 : {
              var_cas_taskOffset = GGS_luint ::constructor_new (_inLexique, GGS_uint (true, 0U), GGS_location (_inLexique) COMMA_HERE) ;
              var_cas_explicitOffset = GGS_bool (true, false) ;
              } break ;
            default :
              break ;
          }
          GGS_luint  var_cas_taskDeadline ;
          switch (select_oa_parser_5 (_inLexique)) {
            case 1 : {
              _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_deadline) COMMA_HERE) ;
              _inLexique._assignFromAttribute_ulongValue (var_cas_taskDeadline) ;
              _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_literal_5Finteger) COMMA_HERE) ;
              } break ;
            case 2 : {
              var_cas_taskDeadline = GGS_luint ::constructor_new (_inLexique, GGS_uint (true, 4294967295U), GGS_location (_inLexique) COMMA_HERE) ;
              } break ;
            default :
              break ;
          }
          GGS_AC_task  var_cas_taskKind ;
          GGS_luint  var_cas_taskProcessorIndex ;
          GGS_luint  var_cas_taskPeriod ;
          switch (select_oa_parser_6 (_inLexique)) {
            case 1 : {
              _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_period) COMMA_HERE) ;
              _inLexique._assignFromAttribute_ulongValue (var_cas_taskPeriod) ;
              _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_literal_5Finteger) COMMA_HERE) ;
              _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_processor) COMMA_HERE) ;
              GGS_lstring  var_cas_taskProcessorName ;
              _inLexique._assignFromAttribute_identifierString (var_cas_taskProcessorName) ;
              _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_identifier) COMMA_HERE) ;
              GGS_luint  automatic_var_0 ;
              const GGS_M_processor  _temp_2759 = var_cas_outProcessorMap ;
              if (_temp_2759._isBuilt ()) {
                _temp_2759 (HERE)->method_searchKeyGetIndex (_inLexique, var_cas_taskProcessorName, var_cas_taskProcessorIndex, automatic_var_0 COMMA_SOURCE_FILE_AT_LINE (100)) ;
              }
              var_cas_taskKind = GGS_C_independantTask ::constructor_new (_inLexique COMMA_HERE) ;
              } break ;
            case 2 : {
              _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_on) COMMA_HERE) ;
              if ((var_cas_explicitOffset).isBuiltAndTrue ()) {
                GGS_location (_inLexique).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "A dependant task cannot have an offset") COMMA_SOURCE_FILE_AT_LINE (105)) ;
              }
              switch (select_oa_parser_7 (_inLexique)) {
                case 1 : {
                  _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_task) COMMA_HERE) ;
                  GGS_lstring  var_cas_masterTaskName ;
                  _inLexique._assignFromAttribute_identifierString (var_cas_masterTaskName) ;
                  _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_identifier) COMMA_HERE) ;
                  GGS_luint  var_cas_every ;
                  switch (select_oa_parser_8 (_inLexique)) {
                    case 1 : {
                      var_cas_every = GGS_luint ::constructor_new (_inLexique, GGS_uint (true, 1U), GGS_location (_inLexique) COMMA_HERE) ;
                      } break ;
                    case 2 : {
                      _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_every) COMMA_HERE) ;
                      _inLexique._assignFromAttribute_ulongValue (var_cas_every) ;
                      _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_literal_5Finteger) COMMA_HERE) ;
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
                  const GGS_M_tasks  _temp_3323 = var_cas_outTaskMap ;
                  if (_temp_3323._isBuilt ()) {
                    _temp_3323 (HERE)->method_searchKeyGetIndex (_inLexique, var_cas_masterTaskName, var_cas_masterTaskIndex, automatic_var_1, automatic_var_2, automatic_var_3, automatic_var_4, automatic_var_5, var_cas_taskProcessorIndex, var_cas_taskPeriod, automatic_var_6 COMMA_SOURCE_FILE_AT_LINE (119)) ;
                  }
                  var_cas_taskKind = GGS_C_taskDependsFromTask ::constructor_new (_inLexique, var_cas_masterTaskIndex, var_cas_every COMMA_HERE) ;
                  } break ;
                case 2 : {
                  _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_message) COMMA_HERE) ;
                  GGS_lstring  var_cas_masterMessageName ;
                  _inLexique._assignFromAttribute_identifierString (var_cas_masterMessageName) ;
                  _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_identifier) COMMA_HERE) ;
                  GGS_luint  var_cas_masterMessageIndex ;
                  GGS_luint  automatic_var_7 ;
                  GGS_luint  automatic_var_8 ;
                  GGS_luint  automatic_var_9 ;
                  GGS_luint  automatic_var_10 ;
                  GGS_luint  automatic_var_11 ;
                  GGS_luint  automatic_var_12 ;
                  GGS_AC_canMessage  automatic_var_13 ;
                  const GGS_M_messages  _temp_3671 = var_cas_outMessagesMap ;
                  if (_temp_3671._isBuilt ()) {
                    _temp_3671 (HERE)->method_searchKeyGetIndex (_inLexique, var_cas_masterMessageName, var_cas_masterMessageIndex, automatic_var_7, automatic_var_8, automatic_var_9, automatic_var_10, automatic_var_11, automatic_var_12, var_cas_taskPeriod, automatic_var_13 COMMA_SOURCE_FILE_AT_LINE (126)) ;
                  }
                  _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_processor) COMMA_HERE) ;
                  GGS_lstring  var_cas_taskProcessorName ;
                  _inLexique._assignFromAttribute_identifierString (var_cas_taskProcessorName) ;
                  _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_identifier) COMMA_HERE) ;
                  GGS_luint  var_cas_every ;
                  switch (select_oa_parser_9 (_inLexique)) {
                    case 1 : {
                      var_cas_every = GGS_luint ::constructor_new (_inLexique, GGS_uint (true, 1U), GGS_location (_inLexique) COMMA_HERE) ;
                      } break ;
                    case 2 : {
                      _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_every) COMMA_HERE) ;
                      _inLexique._assignFromAttribute_ulongValue (var_cas_every) ;
                      _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_literal_5Finteger) COMMA_HERE) ;
                      } break ;
                    default :
                      break ;
                  }
                  GGS_luint  automatic_var_14 ;
                  const GGS_M_processor  _temp_4062 = var_cas_outProcessorMap ;
                  if (_temp_4062._isBuilt ()) {
                    _temp_4062 (HERE)->method_searchKeyGetIndex (_inLexique, var_cas_taskProcessorName, var_cas_taskProcessorIndex, automatic_var_14 COMMA_SOURCE_FILE_AT_LINE (137)) ;
                  }
                  var_cas_taskKind = GGS_C_taskDependsFromMessage ::constructor_new (_inLexique, var_cas_masterMessageIndex, var_cas_every COMMA_HERE) ;
                  } break ;
                default :
                  break ;
              }
              } break ;
            default :
              break ;
          }
          var_cas_outTaskMap.modifier_insertKey (_inLexique, var_cas_taskName, var_cas_taskPriority, var_cas_taskOffset, var_cas_taskDeadline, var_cas_taskDurationMin, var_cas_taskDurationMax, var_cas_taskProcessorIndex, var_cas_taskPeriod, var_cas_taskKind COMMA_SOURCE_FILE_AT_LINE (141)) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1__3B) COMMA_HERE) ;
          } break ;
        case 5 : {
          GGS_luint  var_cas_messageClass ;
          switch (select_oa_parser_10 (_inLexique)) {
            case 1 : {
              _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_standard) COMMA_HERE) ;
              var_cas_messageClass = GGS_luint ::constructor_new (_inLexique, GGS_uint (true, 0U), GGS_location (_inLexique) COMMA_HERE) ;
              _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_message) COMMA_HERE) ;
              } break ;
            case 2 : {
              _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_extended) COMMA_HERE) ;
              var_cas_messageClass = GGS_luint ::constructor_new (_inLexique, GGS_uint (true, 1U), GGS_location (_inLexique) COMMA_HERE) ;
              _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_message) COMMA_HERE) ;
              } break ;
            case 3 : {
              _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_message) COMMA_HERE) ;
              var_cas_messageClass = GGS_luint ::constructor_new (_inLexique, GGS_uint (true, 2U), GGS_location (_inLexique) COMMA_HERE) ;
              } break ;
            default :
              break ;
          }
          GGS_lstring  var_cas_messageName ;
          _inLexique._assignFromAttribute_identifierString (var_cas_messageName) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_identifier) COMMA_HERE) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_network) COMMA_HERE) ;
          GGS_lstring  var_cas_networkName ;
          _inLexique._assignFromAttribute_identifierString (var_cas_networkName) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_identifier) COMMA_HERE) ;
          GGS_luint  var_cas_networkIndex ;
          GGS_bool var_cas_CANnetwork ;
          GGS_luint  automatic_var_15 ;
          const GGS_M_network  _temp_5199 = var_cas_outNetworkMap ;
          if (_temp_5199._isBuilt ()) {
            _temp_5199 (HERE)->method_searchKeyGetIndex (_inLexique, var_cas_networkName, var_cas_networkIndex, var_cas_CANnetwork, automatic_var_15 COMMA_SOURCE_FILE_AT_LINE (171)) ;
          }
          if (((var_cas_CANnetwork)._operator_and ((var_cas_messageClass.reader_uint (_inLexique COMMA_SOURCE_FILE_AT_LINE (172)))._operator_isEqual (GGS_uint (true, 2U)))).isBuiltAndTrue ()) {
            var_cas_messageClass.reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "a CAN message must be either standard either extended") COMMA_SOURCE_FILE_AT_LINE (173)) ;
          }else if ((((var_cas_CANnetwork)._operator_not ())._operator_and ((var_cas_messageClass.reader_uint (_inLexique COMMA_SOURCE_FILE_AT_LINE (174)))._operator_isNotEqual (GGS_uint (true, 2U)))).isBuiltAndTrue ()) {
            var_cas_messageClass.reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "a VAN message cannot be standard or extended") COMMA_SOURCE_FILE_AT_LINE (175)) ;
          }
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_length) COMMA_HERE) ;
          GGS_luint  var_cas_bytesCount ;
          _inLexique._assignFromAttribute_ulongValue (var_cas_bytesCount) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_literal_5Finteger) COMMA_HERE) ;
          if (((var_cas_CANnetwork)._operator_and ((var_cas_bytesCount.reader_uint (_inLexique COMMA_SOURCE_FILE_AT_LINE (180)))._operator_strictSup (GGS_uint (true, 8U)))).isBuiltAndTrue ()) {
            var_cas_bytesCount.reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "CAN message length must be <= 8 bytes") COMMA_SOURCE_FILE_AT_LINE (181)) ;
          }else if ((((var_cas_CANnetwork)._operator_not ())._operator_and ((var_cas_bytesCount.reader_uint (_inLexique COMMA_SOURCE_FILE_AT_LINE (182)))._operator_strictSup (GGS_uint (true, 28U)))).isBuiltAndTrue ()) {
            var_cas_bytesCount.reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "VAN message must be <= 28 bytes") COMMA_SOURCE_FILE_AT_LINE (183)) ;
          }
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_priority) COMMA_HERE) ;
          GGS_luint  var_cas_priority ;
          _inLexique._assignFromAttribute_ulongValue (var_cas_priority) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_literal_5Finteger) COMMA_HERE) ;
          GGS_luint  var_cas_offset ;
          GGS_bool var_cas_explicitOffset ;
          switch (select_oa_parser_11 (_inLexique)) {
            case 1 : {
              _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_offset) COMMA_HERE) ;
              _inLexique._assignFromAttribute_ulongValue (var_cas_offset) ;
              _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_literal_5Finteger) COMMA_HERE) ;
              var_cas_explicitOffset = GGS_bool (true, true) ;
              } break ;
            case 2 : {
              var_cas_offset = GGS_luint ::constructor_new (_inLexique, GGS_uint (true, 0U), GGS_location (_inLexique) COMMA_HERE) ;
              var_cas_explicitOffset = GGS_bool (true, false) ;
              } break ;
            default :
              break ;
          }
          GGS_luint  var_cas_deadline ;
          switch (select_oa_parser_12 (_inLexique)) {
            case 1 : {
              _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_deadline) COMMA_HERE) ;
              _inLexique._assignFromAttribute_ulongValue (var_cas_deadline) ;
              _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_literal_5Finteger) COMMA_HERE) ;
              } break ;
            case 2 : {
              var_cas_deadline = GGS_luint ::constructor_new (_inLexique, GGS_uint (true, 4294967295U), GGS_location (_inLexique) COMMA_HERE) ;
              } break ;
            default :
              break ;
          }
          GGS_AC_canMessage  var_cas_messageKind ;
          GGS_luint  var_cas_period ;
          switch (select_oa_parser_13 (_inLexique)) {
            case 1 : {
              _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_period) COMMA_HERE) ;
              _inLexique._assignFromAttribute_ulongValue (var_cas_period) ;
              _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_literal_5Finteger) COMMA_HERE) ;
              var_cas_messageKind = GGS_C_canIndependantMessage ::constructor_new (_inLexique COMMA_HERE) ;
              } break ;
            case 2 : {
              _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_on) COMMA_HERE) ;
              if ((var_cas_explicitOffset).isBuiltAndTrue ()) {
                GGS_location (_inLexique).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "A dependant task cannot have an offset") COMMA_SOURCE_FILE_AT_LINE (214)) ;
              }
              switch (select_oa_parser_14 (_inLexique)) {
                case 1 : {
                  _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_message) COMMA_HERE) ;
                  GGS_lstring  var_cas_name ;
                  _inLexique._assignFromAttribute_identifierString (var_cas_name) ;
                  _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_identifier) COMMA_HERE) ;
                  GGS_luint  var_cas_messageIndex ;
                  GGS_luint  automatic_var_16 ;
                  GGS_luint  automatic_var_17 ;
                  GGS_luint  automatic_var_18 ;
                  GGS_luint  automatic_var_19 ;
                  GGS_luint  automatic_var_20 ;
                  GGS_luint  automatic_var_21 ;
                  GGS_AC_canMessage  automatic_var_22 ;
                  const GGS_M_messages  _temp_6788 = var_cas_outMessagesMap ;
                  if (_temp_6788._isBuilt ()) {
                    _temp_6788 (HERE)->method_searchKeyGetIndex (_inLexique, var_cas_name, var_cas_messageIndex, automatic_var_16, automatic_var_17, automatic_var_18, automatic_var_19, automatic_var_20, automatic_var_21, var_cas_period, automatic_var_22 COMMA_SOURCE_FILE_AT_LINE (221)) ;
                  }
                  var_cas_messageKind = GGS_C_canMessageFromMessage ::constructor_new (_inLexique, var_cas_messageIndex COMMA_HERE) ;
                  } break ;
                case 2 : {
                  _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_task) COMMA_HERE) ;
                  GGS_lstring  var_cas_taskName ;
                  _inLexique._assignFromAttribute_identifierString (var_cas_taskName) ;
                  _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_identifier) COMMA_HERE) ;
                  GGS_luint  var_cas_taskIndex ;
                  GGS_luint  automatic_var_23 ;
                  GGS_luint  automatic_var_24 ;
                  GGS_luint  automatic_var_25 ;
                  GGS_luint  automatic_var_26 ;
                  GGS_luint  automatic_var_27 ;
                  GGS_luint  automatic_var_28 ;
                  GGS_AC_task  automatic_var_29 ;
                  const GGS_M_tasks  _temp_7063 = var_cas_outTaskMap ;
                  if (_temp_7063._isBuilt ()) {
                    _temp_7063 (HERE)->method_searchKeyGetIndex (_inLexique, var_cas_taskName, var_cas_taskIndex, automatic_var_23, automatic_var_24, automatic_var_25, automatic_var_26, automatic_var_27, automatic_var_28, var_cas_period, automatic_var_29 COMMA_SOURCE_FILE_AT_LINE (228)) ;
                  }
                  var_cas_messageKind = GGS_C_canMessageFromTask ::constructor_new (_inLexique, var_cas_taskIndex COMMA_HERE) ;
                  } break ;
                default :
                  break ;
              }
              } break ;
            default :
              break ;
          }
          var_cas_outMessagesMap.modifier_insertKey (_inLexique, var_cas_messageName, var_cas_messageClass, var_cas_networkIndex, var_cas_bytesCount, var_cas_priority, var_cas_offset, var_cas_deadline, var_cas_period, var_cas_messageKind COMMA_SOURCE_FILE_AT_LINE (232)) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1__3B) COMMA_HERE) ;
          } break ;
        default :
          syntaxRepeat_0 = false ;
          break ;
      }
    }
  }
  _inLexique.acceptTerminal (ACCEPT_TERMINAL (oa_scanner::oa_scanner_1_end) COMMA_HERE) ;
  if (var_cas_outProcessorMap._isBuilt () &&
      var_cas_outNetworkMap._isBuilt () &&
      var_cas_outMessagesMap._isBuilt () &&
      var_cas_outTaskMap._isBuilt ()) {
    ::routine_performComputations (_inLexique,  var_cas_outProcessorMap,  var_cas_outNetworkMap,  var_cas_outMessagesMap,  var_cas_outTaskMap COMMA_SOURCE_FILE_AT_LINE (236)) ;
  }
}

//---------------------------------------------------------------------------*

