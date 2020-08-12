//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_MACROS_LIB_MODULES_H__
#define __HAS_MACROS_LIB_MODULES_H__

#ifdef _MSC_VER
//  Microsoft 
#    define EXPORT __declspec(dllexport)
#    define IMPORT __declspec(dllimport)
#elif defined(__GNUC__)
//  GCC
#    define EXPORT __attribute__((visibility("default")))
#    define IMPORT
#else
//  do nothing and hope for the best?
#    define EXPORT
#    define IMPORT
#    pragma warning Unknown dynamic link import/export semantics.
#endif

#ifdef __cplusplus
#    define C_MODE_BEGIN extern "C" {
#    define C_MODE_END }
#else
#    define C_MODE_BEGIN
#    define C_MODE_END
#endif

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_MACROS_LIB_MODULES_H__