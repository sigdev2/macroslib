//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_MACROS_LIB_CACHE_H__
#define __HAS_MACROS_LIB_CACHE_H__

#ifdef __cplusplus

#include <unordered_map>

#define CACHE_FUNC(IN_TYPE, OUT_TYPE, IN_VAL) static std::unordered_map<IN_TYPE, OUT_TYPE > __static_hash; \
    std::unordered_map<IN_TYPE, OUT_TYPE >::iterator it = __static_hash.find(IN_VAL); \
    if (it != __static_hash.end()) return *it; )
#define RETURN_CACHE_FUNC(IN, OUT) __static_hash[IN] = OUT; return OUT;

#endif // __cplusplus

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_MACROS_LIB_CACHE_H__