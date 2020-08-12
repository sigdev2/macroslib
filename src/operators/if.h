//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_MACROS_LIB_IF_H__
#define __HAS_MACROS_LIB_IF_H__

#include "../config.h"

#include "../preprocessor/utils.h"

#define ifn(...) if (!( __VA_ARGS__ ))
#define elif(...) else if (__VA_ARGS__)
#define elifn(...) else if (!(__VA_ARGS__ ))
#define elseif(...) else if (__VA_ARGS__)
#define elseifn(...) else if (!(__VA_ARGS__ ))

#define ifempty(...) if (IS_EMPTY( __VA_ARGS__ ))
#define ifnempty(...) if (!IS_EMPTY( __VA_ARGS__ ))
#define elifempty(...) else if (IS_EMPTY(__VA_ARGS__))
#define elifnempty(...) else if (!IS_EMPTY(__VA_ARGS__ ))
#define elseifempty(...) else if (IS_EMPTY(__VA_ARGS__))
#define elseifnempty(...) else if (!IS_EMPTY(__VA_ARGS__ ))

#define defval(val, ...) (IS_EMPTY(val) ? ( val ) : __VA_ARGS__)

#define return_if(x, ...) PP_CHECK_IF(( x ), return __VA_ARGS__)
#define return_ifn(x, ...) PP_CHECK_IF(!( x ), return __VA_ARGS__)
#define retif(x, ...) return_if(( x ), __VA_ARGS__)
#define retifn(x, ...) return_ifn(( x ), __VA_ARGS__)
#define true_if(...) return_if(__VA_ARGS__, true)
#define false_if(...) return_if(__VA_ARGS__, false)
#define true_ifn(...) return_ifn(__VA_ARGS__, true)
#define false_ifn(...) return_ifn(__VA_ARGS__, false)

#ifdef __cplusplus

#endif // __cplusplus

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_MACROS_LIB_IF_H__