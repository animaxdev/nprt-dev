//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        File 'option-oa_cli_options-cocoa.m'                                         *
//                                             Generated by version 3.0.0                                              *
//                                         september 23th, 2014, at 21h24'53"                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------------------------------------------------*

#import "option-oa_cli_options-cocoa.h"
#import "OC_GGS_CommandLineOption.h"

//---------------------------------------------------------------------------------------------------------------------*

void enterOptionsFor_oa_5F_cli_5F_options (NSMutableArray * ioBoolOptionArray,
                                                       NSMutableArray * ioUIntOptionArray,
                                                       NSMutableArray * ioStringOptionArray) {
  OC_GGS_CommandLineOption * option ;
  option = [[OC_GGS_CommandLineOption alloc]
    initWithDomainName:@"oa_cli_options"
    identifier:@"createIntermediateFiles"
    commandChar:67
    commandString:@"create-intermediate-files"
    comment:@"Create the intermediate files"
    defaultValue:@""
  ] ;
  [ioBoolOptionArray addObject:option] ;
  option = [[OC_GGS_CommandLineOption alloc]
    initWithDomainName:@"oa_cli_options"
    identifier:@"useCANmaxLegth"
    commandChar:77
    commandString:@"use-can-max-length"
    comment:@"Use only CAN messages max length"
    defaultValue:@""
  ] ;
  [ioBoolOptionArray addObject:option] ;
}

//---------------------------------------------------------------------------------------------------------------------*

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2


