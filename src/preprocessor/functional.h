//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_MACROS_LIB_FUNCTIONAL_H__
#define __HAS_MACROS_LIB_FUNCTIONAL_H__

/*! \file functional.h
    \brief functional macros
    
    Depend from:
     - /preprocessor/utils.h
*/

#include "utils.h"

// RECURSION

#define PP_REC_EVAL_255( ... ) PP_REC_EVAL_127( PP_REC_EVAL_127( __VA_ARGS__ ) )
#define PP_REC_EVAL_127( ... ) PP_REC_EVAL_63( PP_REC_EVAL_63( __VA_ARGS__ ) )
#define PP_REC_EVAL_63( ... ) PP_REC_EVAL_31( PP_REC_EVAL_31( __VA_ARGS__ ) )
#define PP_REC_EVAL_31( ... ) PP_REC_EVAL_15( PP_REC_EVAL_15( __VA_ARGS__ ) )
#define PP_REC_EVAL_15( ... ) PP_REC_EVAL_7( PP_REC_EVAL_7( __VA_ARGS__ ) )
#define PP_REC_EVAL_7( ... ) PP_REC_EVAL_3( PP_REC_EVAL_3( __VA_ARGS__ ) )
#define PP_REC_EVAL_3( ... ) PP_REC_EVAL_1( PP_REC_EVAL_1( __VA_ARGS__ ) )
#define PP_REC_EVAL_1( ... ) __VA_ARGS__

/*!
   \brief Causes 256 rounds of evaluation of its arguments. This enables a crude form of recursion, with a maximum call-depth of 256. Each recursive macro needs to provide its own recursive evaluator, because a recursive evaluator can't be used recursively itself. This allows for recursive macros to be implemented with other recursive macros.
   \param __VA_ARGS__ function to recurtion
   \returns recursion
*/
#define PP_REC_EVAL(...) PP_REC_EVAL_255( __VA_ARGS__ )

// OPERATIONS

/*!
   \brief Return \a head of arguments list
   \param head head of arguments list.
   \param __VA_ARGS__ tail of arguments list.
   \returns \a head of arguments list.
*/
#define PP_HEAD( head , ... ) head

/*!
   \brief Return tail of arguments list
   \param head head of arguments list.
   \param __VA_ARGS__ tail of arguments list.
   \returns tail of arguments list
*/
#define PP_TAIL( head , ... ) __VA_ARGS__


// PP_F_ENDED


/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_MACROS_LIB_FUNCTIONAL_H__