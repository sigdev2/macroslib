//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_MACROS_LIB_POINTERS_H__
#define __HAS_MACROS_LIB_POINTERS_H__

#include "../config.h"

#include "../preprocessor/utils.h"

#ifdef __cplusplus

// note: do not use expressions
#define DELETE(pointer) PP_DO_SAFE(delete pointer ; pointer = NULL)

#endif // __cplusplus

/////////////////////////////////////////////////////////////////////////////
#endif //__HAS_MACROS_LIB_POINTERS_H__