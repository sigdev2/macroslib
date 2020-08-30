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

// VA_ZIP

/*!
   \brief Apply \a macro to every item of arguments list and append semicolon. Maximum iterate is PP_VA_MAXARGS arguments.
   \param macro functional macro take one argument - list item
   \param __VA_ARGS__ arguments list
   \returns result of \a macro call on every arguments as list with separated and ended the semicolon
*/
#define PP_VA_ZIP(list1, list2, zipper) PP_INVOKE( PP_VA_FOR, ( PP_VA_SEMICOLON_LIST_ITEM, macro, __VA_ARGS__ ) )

// VA_REPEAT

/*!
   \brief Repeat some code or value passed in \a value \a count times. Maximum is PP_VA_MAXARGS times.
   \param value some code or value
   \param count times to repeat
   \returns repeated \a value
*/
#define PP_VA_REPEAT(value, count)  PP_INVOKE( PP_VA_FOR, ( PP_VA_FOR_ITEM_DATA , value , PP_VA_GEN_A_N( count ) )) )

/*!
   \brief Repeat some code or value passed in  \a value \a count times with apply \a macro to every time. Maximum is PP_VA_MAXARGS times.
   \param macro functional macro take one argument - \a value
   \param value some code or value
   \param count times to repeat
   \returns repeated \a value with apply \a macro
*/
#define PP_VA_REPEAT(macro, value, count)  PP_INVOKE( PP_VA_FOR, ( PP_VA_FOR_ITEM_DATA , PP_INVOKE( macro , ( value )) , PP_INVOKE( PP_VA_GEN_A_N, ( count ) ) )) )

/*!
   \brief Repeat some code or value passed in  \a value \a count times with apply \a macro to every time and separate commas. Maximum is PP_VA_MAXARGS times.
   \param macro functional macro take one argument - \a value
   \param value some code or value
   \param count times to repeat
   \returns repeated \a value with apply \a macro and separate commas
*/
#define PP_VA_REPEAT_COMMA(macro, value, count) PP_INVOKE( macro , value ) PP_COMMA PP_INVOKE( PP_VA_FOR, ( PP_VA_FOR_ITEM_DATA , PP_INVOKE( macro , ( value )), PP_INVOKE( PP_VA_GEN_A_N, ( PP_INVOKE( PP_VA_DECREMENT, ( count )) ) ) ))

/*!
   \brief Repeat some code or value passed in  \a value \a count times with apply \a macro to every time and append semicolon. Maximum is PP_VA_MAXARGS times.
   \param macro functional macro take one argument - \a value
   \param value some code or value
   \param count times to repeat
   \returns repeated \a value with apply \a macro and append semicolon
*/
#define PP_VA_REPEAT_SEMICOLON(macro, value, count) PP_INVOKE( PP_VA_REPEAT, ( macro, value PP_SEMICOLON , count ) )

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_MACROS_LIB_FUNCTIONAL_H__