//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_MACROS_LIB_SWITCH_H__
#define __HAS_MACROS_LIB_SWITCH_H__

#include "../preprocessor/variadic.h"

#define SWITCH_BEGIN(...) switch(__VA_ARGS__) {
#define SWITCH_END }

#define CASE(key, ...) case ( key ): { ( __VA_ARGS__ ) break; }
#define RETCASE(key, ...) case ( key ): return ( __VA_ARGS__ );

#define DEFCASE_0
#define DEFCASE_1(val) default: { ( val ); break; }
#define DEFCASE_2(key, val) default: case ( key ): { ( val ) break; }
#define DEFCASE(...) PP_VA_FUNC(DEFCASE, __VA_ARGS__)

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_MACROS_LIB_SWITCH_H__