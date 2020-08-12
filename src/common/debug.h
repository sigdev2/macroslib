//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_MACROS_LIB_DEBUG_H__
#define __HAS_MACROS_LIB_DEBUG_H__

#include "templates.h"
#include "versions.h"
#include "../preprocessor/utils.h"


// messages

#if (defined DEBUG || defined _DEBUG)
#    include <assert.h>
#    define DO_DEBUG(...) PP_DO_SAFE( __VA_ARGS__ )
#else
#    define DO_DEBUG(...)
#endif // DEBUG || _DEBUG

#ifndef __FUNCTION_DECL__
#    if defined(__GNUC__) || (defined(__MWERKS__) && (__MWERKS__ >= 0x3000)) || (defined(__ICC) && (__ICC >= 600)) || defined(__ghs__)
#        define __FUNCTION_DECL__ __PRETTY_FUNCTION__
#    elif defined(__DMC__) && (__DMC__ >= 0x810)
#        define __FUNCTION_DECL__ __PRETTY_FUNCTION__
#    elif defined(__FUNCSIG__)
#        define __FUNCTION_DECL__ __FUNCSIG__
#    elif (defined(__INTEL_COMPILER) && (__INTEL_COMPILER >= 600)) || (defined(__IBMCPP__) && (__IBMCPP__ >= 500))
#        define __FUNCTION_DECL__ __FUNCTION__
#    elif defined(__BORLANDC__) && (__BORLANDC__ >= 0x550)
#        define __FUNCTION_DECL__ __FUNC__
#    elif defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901)
#        define __FUNCTION_DECL__ __func__
#    elif defined(__cplusplus) && (__cplusplus >= 201103)
#        define __FUNCTION_DECL__ __func__
#    else
#       define __FUNCTION_DECL__ "(unknown)" // note: unsupported
#    endif // __FUNCTION_DECL__
#endif // __FUNCTION_DECL__

#ifdef __cplusplus
#    include <stdio.h>
#    define DEBUG_PRINT(...) DO_DEBUG(DEBUG_OUT << __VA_ARGS__ )
#    define DEBUG_LOG(...) DEBUG_PRINT(#__VA_ARGS__ << " = [" << ( __VA_ARGS__ ) << "]\n")
#    define DEBUG_TRACE(...) DEBUG_PRINT( ( __VA_ARGS__ ) << "\nCallstack: " << \
            #__VA_ARGS__ << __FUNCTION_DECL__ << '[' << __FILE__ << ':' << __LINE__ << "]\n" )
#else // !__cplusplus
#    include <stdio.h>
#    define DEBUG_PRINT(...) DO_DEBUG(fprintf(DEBUG_OUT, __VA_ARGS__ ))
#    define DEBUG_LOG(...) DEBUG_PRINT( "%s = [ %s ]\n", #__VA_ARGS__, ( __VA_ARGS__ ))
#    define DEBUG_TRACE(...) DEBUG_PRINT( "%s\nCallstack: %s [%s:%d]\n", ( __VA_ARGS__ ), \
            #__VA_ARGS__, __FUNCTION_DECL__, __FILE__, __LINE__,)
#endif // __cplusplus

#ifdef _WIN32
#    pragma comment( lib, "user32.lib" )
#    include <winuser.h>
#    define DEBUG_MESSAGE(...) DO_DEBUG(MessageBoxA(0, ( __VA_ARGS__ ), "Debug", 0))
#else // !_WIN32
#    define DEBUG_MESSAGE(...) DEBUG_PRINT( ( __VA_ARGS__ ) )
#endif // _WIN32


// aliases

#ifndef _dbg
#    define _dbg(...) DO_DEBUG(__VA_ARGS__)
#endif // _dbg

#ifndef _dprint
#    define _dprint(...) DEBUG_PRINT(__VA_ARGS__)
#endif // _dprint

#ifndef _dlog
#    define _dlog(...) DEBUG_LOG(__VA_ARGS__)
#endif // _dlog

#ifndef _trace
#    define _trace(...) DEBUG_TRACE(__VA_ARGS__)
#endif // _trace

#ifndef _dmsg
#    define _dmsg(...) DEBUG_LOG(__VA_ARGS__)
#endif // _dmsg

// assert

#define _ass(...) DO_DEBUG(assert(__VA_ARGS__))
#define _assn(...) DO_DEBUG(assert(!(__VA_ARGS__)))


// revert if assert, assert if, assert return if

#define PP_ASSERT_CHECK_IF(x, ...) PP_DO_SAFE(const bool ___some_b_value=( x ); _ass(!___some_b_value); if (___some_b_value) { __VA_ARGS__; })
#define assert_if(x, ...) PP_ASSERT_CHECK_IF(( x ), __VA_ARGS__ )
#define assert_ifn(x, ...) PP_ASSERT_CHECK_IF(!( x ), __VA_ARGS__ )
#define assert_retif(x, ...) assert_if(( x ), return __VA_ARGS__ )
#define assert_retifn(x, ...) assert_ifn(( x ), return __VA_ARGS__ )
#define assert_trueif(...) assert_if( __VA_ARGS__ , return true )
#define assert_falseif(...) assert_if( __VA_ARGS__ , return false )
#define assert_trueifn(...) assert_ifn( __VA_ARGS__ , return true )
#define assert_falseifn(...) assert_ifn( __VA_ARGS__ , return false )


// rif

#define _rif(x, ...) assert_if(( x ), __VA_ARGS__ )
#define _rifn(x, ...) assert_ifn(( x ), __VA_ARGS__ )
#define _rifret(x, ...) assert_retif(( x ), __VA_ARGS__ )
#define _rifnret(x, ...) assert_retifn(( x ), __VA_ARGS__ )
#define _rtrueif(...) assert_trueif(__VA_ARGS__)
#define _rfalseif(...) assert_falseif(__VA_ARGS__)
#define _rtrueifn(...) assert_trueifn(__VA_ARGS__)
#define _rfalseifn(...) assert_falseifn(__VA_ARGS__)


// if asserts

#define ifa(x, ...) assert_if(( x ), __VA_ARGS__  )
#define ifna(x, ...) assert_ifn(( x ), __VA_ARGS__  )
#define return_ifa(x, ...) assert_retif(( x ), __VA_ARGS__ )
#define return_ifna(x, ...) assert_retifn(( x ), __VA_ARGS__ )
#define retifa(x, ...) assert_retif(( x ), __VA_ARGS__ )
#define retifna(x, ...) assert_retifn(( x ), __VA_ARGS__ )
#define true_ifa(...) assert_trueif(__VA_ARGS__)
#define false_ifa(...) assert_falseif(__VA_ARGS__)
#define true_ifna(...) assert_trueifn(__VA_ARGS__)
#define false_ifna(...) assert_falseifn(__VA_ARGS__)


// type assert

#ifdef __cplusplus

namespace __MacrosLibPrivate
{
#ifdef CXX11
	template<typename ... T>
    struct TVoid {};
#else // CXX11
    template<TEMPLATES_ARGS_VOID_N(PP_VA_MAXARGS)>
    struct TVoid {};
#endif // CXX11
}

#define TYPE_ASSERT(...) __MacrosLibPrivate::TVoid< __VA_ARGS__ >
#define TYPE_EXIST(...) TYPE_ASSERT(__VA_ARGS__)

#endif // __cplusplus

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_MACROS_LIB_DEBUG_H__