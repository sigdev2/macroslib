//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_MACROS_LIB_NOEXCEPT_H__
#define __HAS_MACROS_LIB_NOEXCEPT_H__

#include "../common/versions.h"
#include "../preprocessor/variadic.h"

#ifdef CXX11
#    define NOEXCEPT(...) noexcept VA_ARGS_LIST( __VA_ARGS__ )
#else // CXX11
#    define NOEXCEPT(...)
#endif // CXX11

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_MACROS_LIB_NOEXCEPT_H__