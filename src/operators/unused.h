//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_MACROS_LIB_UNUSED_H__
#define __HAS_MACROS_LIB_UNUSED_H__

#include "../preprocessor/utils.h"
#include "../preprocessor/variadic.h"

// note: disable warrings for unused variables

#define UNUSED_SINGLE( dummy, var ) ((void) var) PP_SEMICOLON
#define unused(...) PP_INVOKE( VA_LIST, (UNUSED_SINGLE, __VA_ARGS__ ) )

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_MACROS_LIB_UNUSED_H__