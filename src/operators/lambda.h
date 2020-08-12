//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_MACROS_LIB_LAMBDA_H__
#define __HAS_MACROS_LIB_LAMBDA_H__

#include "../common/versions.h"
#include "../preprocessor/variadic.h"

#ifdef CXX11
#    define LAMBDA_0
#    define LAMBDA_1(ret) []() { return ( ret ); }
#    define LAMBDA_2(arg, ret) [] arg { return ( ret ); }
#    define LAMBDA_3(scope, arg, ret) scope arg { return ( ret ); }
#    define LAMBDA(...) PP_VA_FUNC(LAMBDA, __VA_ARGS__)
#endif // C++11

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_MACROS_LIB_LAMBDA_H__