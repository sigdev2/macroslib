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

/*!
   \brief Return \a head of arguments list. Lisp style PP_HEAD alias
   \param head head of arguments list.
   \param __VA_ARGS__ tail of arguments list.
   \returns \a head of arguments list.
*/
#define PP_CAR( head , ... ) head

/*!
   \brief Return tail of arguments list. Lisp style PP_TAIL alias
   \param head head of arguments list.
   \param __VA_ARGS__ tail of arguments list.
   \returns tail of arguments list
*/
#define PP_CDR( head , ... ) __VA_ARGS__

/*!
   \brief Lisp style short entry PP_HEAD and PP_TAIL conbinations:

      caar head of head
      cadr tail of head
      cdar head of tail or second
      cddr tail of tail
      caaar head of head of head
      caadr tail of head of head
      caddr tail of tail of head
      cdddr tail of tail of tail
      cadar head of tail of head
      cdadr tail of head of tail
      cdaar head of head of tail
      cddar head of tail of tail or third
      caaaar head of head of head of head
      cddddr tail of tail of tail
      caaadr taile of head of head of head
      caadar head of tail of head of head
      cadaar head of head of taile of head
      cdaaar head of head of head of tail
      caaddr tail of tail of head of head
      cadadr tail of head of tail of head
      caddar head of tail of taile of head
      cdaadr tail of head of head of tail
      cdadar head of tail of head of tail
      cddaar head of head of tail of tail
      cdaddr tail of tail of head of tail
      cddadr tail of head of tail of tail
      cdddar head of tail of tail of tail or fourth
      cadddr tail of tail of tail of head

   \param __VA_ARGS__ arguments list.
   \returns head-head of arguments list.
*/
#define PP_CAAR( ... ) PP_INVOKE(PP_HEAD, ( PP_UNPAREN( PP_HEAD( __VA_ARGS__ ) ) ) )
#define PP_CADR( ... ) PP_INVOKE(PP_TAIL, ( PP_UNPAREN( PP_HEAD( __VA_ARGS__ ) ) ) )
#define PP_CDAR( ... ) PP_INVOKE(PP_HEAD, ( PP_UNPAREN( PP_TAIL( __VA_ARGS__ ) ) ) )
#define PP_CDDR( ... ) PP_INVOKE(PP_TAIL, ( PP_UNPAREN( PP_TAIL( __VA_ARGS__ ) ) ) )
#define PP_CAAAR( ... ) PP_INVOKE(PP_HEAD, ( PP_UNPAREN( PP_INVOKE(PP_HEAD, ( PP_UNPAREN( PP_HEAD( __VA_ARGS__ ) ) ) ) ) ) )
#define PP_CAADR( ... ) PP_INVOKE(PP_TAIL, ( PP_UNPAREN( PP_INVOKE(PP_HEAD, ( PP_UNPAREN( PP_HEAD( __VA_ARGS__ ) ) ) ) ) ) )
#define PP_CADAR( ... ) PP_INVOKE(PP_HEAD, ( PP_UNPAREN( PP_INVOKE(PP_TAIL, ( PP_UNPAREN( PP_HEAD( __VA_ARGS__ ) ) ) ) ) ) )
#define PP_CDAAR( ... ) PP_INVOKE(PP_HEAD, ( PP_UNPAREN( PP_INVOKE(PP_HEAD, ( PP_UNPAREN( PP_TAIL( __VA_ARGS__ ) ) ) ) ) ) )
#define PP_CADDR( ... ) PP_INVOKE(PP_TAIL, ( PP_UNPAREN( PP_INVOKE(PP_TAIL, ( PP_UNPAREN( PP_HEAD( __VA_ARGS__ ) ) ) ) ) ) )
#define PP_CDDAR( ... ) PP_INVOKE(PP_HEAD, ( PP_UNPAREN( PP_INVOKE(PP_TAIL, ( PP_UNPAREN( PP_TAIL( __VA_ARGS__ ) ) ) ) ) ) )
#define PP_CDADR( ... ) PP_INVOKE(PP_TAIL, ( PP_UNPAREN( PP_INVOKE(PP_HEAD, ( PP_UNPAREN( PP_TAIL( __VA_ARGS__ ) ) ) ) ) ) )
#define PP_CDDDR( ... ) PP_INVOKE(PP_TAIL, ( PP_UNPAREN( PP_INVOKE(PP_TAIL, ( PP_UNPAREN( PP_TAIL( __VA_ARGS__ ) ) ) ) ) ) )
#define PP_CAAAAR( ... ) PP_INVOKE(PP_HEAD, ( PP_UNPAREN( PP_INVOKE(PP_HEAD, ( PP_UNPAREN( PP_INVOKE(PP_HEAD, ( PP_UNPAREN( PP_HEAD( __VA_ARGS__ ) ) ) ) ) ) ) ) ) )
#define PP_CDDDDR( ... ) PP_INVOKE(PP_TAIL, ( PP_UNPAREN( PP_INVOKE(PP_TAIL, ( PP_UNPAREN( PP_INVOKE(PP_TAIL, ( PP_UNPAREN( PP_TAIL( __VA_ARGS__ ) ) ) ) ) ) ) ) ) )
#define PP_CAAADR( ... ) PP_INVOKE(PP_TAIL, ( PP_UNPAREN( PP_INVOKE(PP_HEAD, ( PP_UNPAREN( PP_INVOKE(PP_HEAD, ( PP_UNPAREN( PP_HEAD( __VA_ARGS__ ) ) ) ) ) ) ) ) ) )
#define PP_CAADAR( ... ) PP_INVOKE(PP_HEAD, ( PP_UNPAREN( PP_INVOKE(PP_TAIL, ( PP_UNPAREN( PP_INVOKE(PP_HEAD, ( PP_UNPAREN( PP_HEAD( __VA_ARGS__ ) ) ) ) ) ) ) ) ) )
#define PP_CADAAR( ... ) PP_INVOKE(PP_HEAD, ( PP_UNPAREN( PP_INVOKE(PP_HEAD, ( PP_UNPAREN( PP_INVOKE(PP_TAIL, ( PP_UNPAREN( PP_HEAD( __VA_ARGS__ ) ) ) ) ) ) ) ) ) )
#define PP_CDAAAR( ... ) PP_INVOKE(PP_HEAD, ( PP_UNPAREN( PP_INVOKE(PP_HEAD, ( PP_UNPAREN( PP_INVOKE(PP_HEAD, ( PP_UNPAREN( PP_TAIL( __VA_ARGS__ ) ) ) ) ) ) ) ) ) )
#define PP_CAADDR( ... ) PP_INVOKE(PP_TAIL, ( PP_UNPAREN( PP_INVOKE(PP_TAIL, ( PP_UNPAREN( PP_INVOKE(PP_HEAD, ( PP_UNPAREN( PP_HEAD( __VA_ARGS__ ) ) ) ) ) ) ) ) ) )
#define PP_CADADR( ... ) PP_INVOKE(PP_TAIL, ( PP_UNPAREN( PP_INVOKE(PP_HEAD, ( PP_UNPAREN( PP_INVOKE(PP_TAIL, ( PP_UNPAREN( PP_HEAD( __VA_ARGS__ ) ) ) ) ) ) ) ) ) )
#define PP_CDADAR( ... ) PP_INVOKE(PP_HEAD, ( PP_UNPAREN( PP_INVOKE(PP_TAIL, ( PP_UNPAREN( PP_INVOKE(PP_HEAD, ( PP_UNPAREN( PP_TAIL( __VA_ARGS__ ) ) ) ) ) ) ) ) ) )
#define PP_CADDAR( ... ) PP_INVOKE(PP_HEAD, ( PP_UNPAREN( PP_INVOKE(PP_TAIL, ( PP_UNPAREN( PP_INVOKE(PP_TAIL, ( PP_UNPAREN( PP_HEAD( __VA_ARGS__ ) ) ) ) ) ) ) ) ) )
#define PP_CDAADR( ... ) PP_INVOKE(PP_TAIL, ( PP_UNPAREN( PP_INVOKE(PP_HEAD, ( PP_UNPAREN( PP_INVOKE(PP_HEAD, ( PP_UNPAREN( PP_TAIL( __VA_ARGS__ ) ) ) ) ) ) ) ) ) )
#define PP_CDDAAR( ... ) PP_INVOKE(PP_HEAD, ( PP_UNPAREN( PP_INVOKE(PP_HEAD, ( PP_UNPAREN( PP_INVOKE(PP_TAIL, ( PP_UNPAREN( PP_TAIL( __VA_ARGS__ ) ) ) ) ) ) ) ) ) )
#define PP_CADDDR( ... ) PP_INVOKE(PP_TAIL, ( PP_UNPAREN( PP_INVOKE(PP_TAIL, ( PP_UNPAREN( PP_INVOKE(PP_TAIL, ( PP_UNPAREN( PP_HEAD( __VA_ARGS__ ) ) ) ) ) ) ) ) ) )
#define PP_CDADDR( ... ) PP_INVOKE(PP_TAIL, ( PP_UNPAREN( PP_INVOKE(PP_TAIL, ( PP_UNPAREN( PP_INVOKE(PP_HEAD, ( PP_UNPAREN( PP_TAIL( __VA_ARGS__ ) ) ) ) ) ) ) ) ) )
#define PP_CDDADR( ... ) PP_INVOKE(PP_TAIL, ( PP_UNPAREN( PP_INVOKE(PP_HEAD, ( PP_UNPAREN( PP_INVOKE(PP_TAIL, ( PP_UNPAREN( PP_TAIL( __VA_ARGS__ ) ) ) ) ) ) ) ) ) )
#define PP_CDDDAR( ... ) PP_INVOKE(PP_HEAD, ( PP_UNPAREN( PP_INVOKE(PP_TAIL, ( PP_UNPAREN( PP_INVOKE(PP_TAIL, ( PP_UNPAREN( PP_TAIL( __VA_ARGS__ ) ) ) ) ) ) ) ) ) )

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