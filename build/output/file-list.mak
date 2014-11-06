#----------------------------------------------------------------------------------------------------------------------*

#--- LIBPM directory
LIBPM_DIRECTORY_PATH := ../build/libpm

#----------------------------------------------------------------------------------------------------------------------*
#                                                                                                                      *
#     Project source files directories                                                                                 *
#                                                                                                                      *
#----------------------------------------------------------------------------------------------------------------------*

SOURCES_DIR := ../build/output
SOURCES_DIR += ../build/user-headers
SOURCES_DIR += $(LIBPM_DIRECTORY_PATH)
SOURCES_DIR += ../hand_coded_sources

#----------------------------------------------------------------------------------------------------------------------*
#                                                                                                                      *
#     Source files names list (without their actual path)                                                              *
#                                                                                                                      *
#----------------------------------------------------------------------------------------------------------------------*

SOURCES :=

#--- Galgas 2 ---------------------------------------------------------------------------------------------------------*
SOURCES += all-galgas.cpp

#--- Files from LIBPM -------------------------------------------------------------------------------------------------*
SOURCES += all-libpm.cpp

#--- Files generated by GALGAS ----------------------------------------------------------------------------------------*
SOURCES += all-declarations-0.cpp

#--- Hand-coded files -------------------------------------------------------------------------------------------------*
SOURCES += C_us.cpp
SOURCES += activities_core.cpp
SOURCES += C_activitiesToSchedule.cpp
SOURCES += C_VDL_hashmap.cpp
SOURCES += calculs_activites-v2.cpp
SOURCES += CANMmessageBounds.cpp
SOURCES += ExtendedList-v2.cpp
SOURCES += ExtractRTs-v2.cpp
SOURCES += independant_resources_core.cpp
SOURCES += VerifyConditions-v2.cpp
SOURCES += C_us_hashmap.cpp


#----------------------------------------------------------------------------------------------------------------------*
#                                                                                                                      *
#     Link                                                                                                             *
#                                                                                                                      *
#----------------------------------------------------------------------------------------------------------------------*

USER_LINK_OPTIONS :=


#----------------------------------------------------------------------------------------------------------------------*
#                                                                                                                      *
#     Command line options                                                                                             *
#                                                                                                                      *
#----------------------------------------------------------------------------------------------------------------------*

USER_COMMAND_LINE_OPTIONS :=
USER_COMMAND_LINE_OPTIONS += -DLIBPM_MULTI_THREADING=0

#----------------------------------------------------------------------------------------------------------------------*