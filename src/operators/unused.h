//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_MACROS_LIB_UNUSED_H__
#define __HAS_MACROS_LIB_UNUSED_H__

/*! \file unused.h
    \brief Unused operator

    Depend from:
     - /preprocessor/utils.h
     - /preprocessor/variadic.h
*/

#include "../preprocessor/utils.h"
#include "../preprocessor/variadic.h"

#define UNUSED_SINGLE( dummy, var ) ((void) var) PP_SEMICOLON
/*!
   \brief Disable warrings for unused variables
   \param __VA_ARGS__ unsused variables.
   \returns void casting variables.
*/
#define unused(...) PP_INVOKE( VA_LIST, (UNUSED_SINGLE, __VA_ARGS__ ) )

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_MACROS_LIB_UNUSED_H__