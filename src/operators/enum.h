//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_MACROS_LIB_ENUM_H__
#define __HAS_MACROS_LIB_ENUM_H__

#include "switch.h"
#include "../common/debug.h"
#include "../preprocessor/utils.h"
#include "../preprocessor/variadic.h"

#ifdef __cplusplus

// #define ENUM_HANDLE part1, part2, part3

#define DEFINE_ENUM_MEMBER(name) PP_COMMA name
#define DEFINE_ENUM(name, ...) enum name {  PP_INVOKE( PP_HEAD, (__VA_ARGS__) ) PP_INVOKE( VA_LIST, ( DEFINE_ENUM_MEMBER, PP_INVOKE( PP_TAIL, (__VA_ARGS__) )) ) };
#define DEFINE_ENUM_NUM(name, ...) enum name {  PP_INVOKE( PP_HEAD, (__VA_ARGS__) ) = 0 PP_INVOKE( VA_LIST, ( DEFINE_ENUM_MEMBER, PP_INVOKE( PP_TAIL, (__VA_ARGS__) )) ) };

#define ENUM_MEMBER_TO_STR_RETCASE(name) RETCASE( name , #name )
#define ENUM_TO_STR_RETCASE(var, ...) SWITCH_BEGIN ( var ) PP_INVOKE( VA_LIST, ( ENUM_MEMBER_TO_STR_RETCASE, __VA_ARGS__) ) DEFCASE( _ass(false); return "<error>" ) SWITCH_END

#define ENUM_OF_STRINGS(name, ...) DEFINE_ENUM_NUM(name, __VA_ARGS__ ) const char* name##_toString(name v) { ENUM_TO_STR_RETCASE( v , __VA_ARGS__) _ass(false); return "<error>"; };

#endif // __cplusplus

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_MACROS_LIB_ENUM_H__