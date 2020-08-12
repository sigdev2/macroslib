//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_MACROS_LIB_TEMPLATES_H__
#define __HAS_MACROS_LIB_TEMPLATES_H__

#include "../preprocessor/variadic.h"

#ifdef __cplusplus

#define TEMPLATES_ARGS_HEAD( dummy , head ) PP_COMMA typename head
#define TEMPLATES_ARGS(...) typename PP_INVOKE(PP_VA_HEAD, (__VA_ARGS__)) PP_VA_FOR(TEMPLATES_ARGS_HEAD, 0, PP_INVOKE(PP_VA_TAIL, (__VA_ARGS__)))
#define TEMPLATES_ARGS_N(NUM) TEMPLATES_ARGS(PP_VA_GEN_A_N( NUM ))

#define TEMPLATES_ARGS_HEAD_VOID( dummy , head ) PP_COMMA typename head = void
#define TEMPLATES_ARGS_VOID(...) typename PP_INVOKE(PP_VA_HEAD, (__VA_ARGS__)) = void PP_VA_FOR(TEMPLATES_ARGS_HEAD_VOID, 0, PP_INVOKE(PP_VA_TAIL, (__VA_ARGS__)))
#define TEMPLATES_ARGS_VOID_N(NUM) TEMPLATES_ARGS_VOID(PP_VA_GEN_A_N( NUM ))

#define TEMPLATES_LIST_HEAD_VOID( dummy1 , dummy2 ) PP_COMMA void
#define TEMPLATES_LIST_VOID(...) void PP_VA_FOR(TEMPLATES_LIST_HEAD_VOID, 0, PP_INVOKE(PP_VA_TAIL, (__VA_ARGS__)))
#define TEMPLATES_LIST_VOID_N(NUM) TEMPLATES_LIST_VOID(PP_VA_GEN_A_N( NUM ))

#define TEMPLATES_ARGS_HEAD_BOOL( dummy , head ) PP_COMMA bool head
#define TEMPLATES_ARGS_BOOL(...) bool PP_INVOKE(PP_VA_HEAD, (__VA_ARGS__)) PP_VA_FOR(TEMPLATES_ARGS_HEAD_BOOL, 0, PP_INVOKE(PP_VA_TAIL, (__VA_ARGS__)))
#define TEMPLATES_ARGS_BOOL_N(NUM) TEMPLATES_ARGS_BOOL(PP_VA_GEN_A_N( NUM ))

#define PUBLIC_INHERIT_HEAD( dummy , head ) PP_COMMA public PP_SINGLE_TYPE_INHERIT( head )
#define IPUBLIC_STATIC(...) public PP_SINGLE_TYPE_INHERIT(PP_INVOKE(PP_VA_HEAD, (__VA_ARGS__))) PP_VA_FOR(PUBLIC_INHERIT_HEAD, 0, PP_INVOKE(PP_VA_TAIL, (__VA_ARGS__)))
#define IPUBLIC(...) IPUBLIC_STATIC(__VA_ARGS__)

#endif // __cplusplus

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_MACROS_LIB_TEMPLATES_H__