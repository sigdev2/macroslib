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
     - /preprocessor/variadic.h
*/

#include "utils.h"
#include "variadic.h"

// RECURSION

#define PP_REC_EVAL_255( macro, ... ) PP_REC_EVAL_127( macro, PP_REC_EVAL_127( macro, __VA_ARGS__ ) )
#define PP_REC_EVAL_127( macro, ... ) PP_REC_EVAL_63( macro, PP_REC_EVAL_63( macro, __VA_ARGS__ ) )
#define PP_REC_EVAL_63( macro, ... ) PP_REC_EVAL_31( macro, PP_REC_EVAL_31( macro, __VA_ARGS__ ) )
#define PP_REC_EVAL_31( macro, ... ) PP_REC_EVAL_15( macro, PP_REC_EVAL_15( macro, __VA_ARGS__ ) )
#define PP_REC_EVAL_15( macro, ... ) PP_REC_EVAL_7( macro, PP_REC_EVAL_7( macro, __VA_ARGS__ ) )
#define PP_REC_EVAL_7( macro, ... ) PP_REC_EVAL_3( macro, PP_REC_EVAL_3( macro, __VA_ARGS__ ) )
#define PP_REC_EVAL_3( macro, ... ) PP_REC_EVAL_1( macro, PP_REC_EVAL_1( macro, __VA_ARGS__ ) )
#define PP_REC_EVAL_1( macro, ... ) macro ( __VA_ARGS__ )

/*!
   \brief Causes 256 rounds of evaluation of its arguments in \a macro.
   This enables a crude form of recursion, with a maximum call-depth of 256.
   Each recursive macro needs to provide its own recursive stack name in \a macro arguments, because a recursive evaluator can't be used recursively itself.
   This allows for recursive macros to be implemented with other recursive macros.
   Please don't use it because it depends on preprocessing behavior of GCC and Clang that may not conform to the ISO standards and it is also slower than calling variadic macros.
   \param macro recursion stack name, must be defined, functional macro with variadic arguments
   \param __VA_ARGS__ functional macros to recurtion
   \returns recursion
*/
#define PP_REC_EVAL( macro, ...) PP_REC_EVAL_255( macro, __VA_ARGS__ )

// ACCESS OPERATORS

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
#define PP_CAR( ... ) PP_HEAD( __VA_ARGS__ )

/*!
   \brief Return tail of arguments list. Lisp style PP_TAIL alias
   \param head head of arguments list.
   \param __VA_ARGS__ tail of arguments list.
   \returns tail of arguments list
*/
#define PP_CDR( ... ) PP_TAIL( __VA_ARGS__ )

/*!
   \brief Lisp style short entry PP_HEAD and PP_TAIL conbinations:

      caar - head of head,
      cadr - tail of head,
      cdar - head of tail or second,
      cddr - tail of tail,
      caaar - head of head of head,
      caadr - tail of head of head,
      caddr - tail of tail of head,
      cdddr - tail of tail of tail,
      cadar - head of tail of head,
      cdadr - tail of head of tail,
      cdaar - head of head of tail,
      cddar - head of tail of tail or third,
      caaaar - head of head of head of head,
      cddddr - tail of tail of tail,
      caaadr - taile of head of head of head,
      caadar - head of tail of head of head,
      cadaar - head of head of taile of head,
      cdaaar - head of head of head of tail,
      caaddr - tail of tail of head of head,
      cadadr - tail of head of tail of head,
      caddar - head of tail of taile of head,
      cdaadr - tail of head of head of tail,
      cdadar - head of tail of head of tail,
      cddaar - head of head of tail of tail,
      cdaddr - tail of tail of head of tail,
      cddadr - tail of head of tail of tail,
      cdddar - head of tail of tail of tail or fourth,
      cadddr - tail of tail of tail of head

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

/*!
   \brief Return fisrt element of arguments list. PP_HEAD alias
   \param head head of arguments list.
   \param __VA_ARGS__ tail of arguments list.
   \returns fisrt element of arguments list
*/
#define PP_FIRST( ... ) PP_HEAD( __VA_ARGS__ )

/*!
   \brief Return second element of arguments list. Is simplification of PP_CDAR.
   \param f first element of arguments list
   \param s second element of arguments list
   \param __VA_ARGS__ tail of arguments list.
   \returns second element of arguments list
*/
#define PP_SECOND(f, s, ... ) s

/*!
   \brief Return third element of arguments list. Is simplification of PP_CDDAR.
   \param f first element of arguments list
   \param s second element of arguments list
   \param t third element of arguments list
   \param __VA_ARGS__ tail of arguments list.
   \returns third element of arguments list
*/
#define PP_THIRD(f, s, t, ... ) t

/*!
   \brief Return fourth element of arguments list. Is simplification of PP_CDDDAR.
   \param f first element of arguments list
   \param s second element of arguments list
   \param t third element of arguments list
   \param fh fourth element of arguments list
   \param __VA_ARGS__ tail of arguments list.
   \returns fourth element of arguments list
*/
#define PP_FOURTH(f, s, t, fh, ... ) fh

/*!
   \brief Return element of arguments list by \a position. Arguments list size must be not greater than PP_VA_MAXARGS
   \param position position from 0 to PP_VA_MAXARGS
   \param __VA_ARGS__ arguments list.
   \returns last element of arguments list
*/
#define PP_TAKE( position , ...) PP_INVOKE(PP_CAT( PP_VA_GET_POS_ , position ), (__VA_ARGS__))

/*!
   \brief Return last element of arguments list. Arguments list must be not more than PP_VA_MAXARGS
   \param __VA_ARGS__ arguments list.
   \returns last element of arguments list
*/
#define PP_LAST( ... ) PP_TAKE( PP_VA_DECREMENT(PP_VA_SIZE( __VA_ARGS__ )), __VA_ARGS__ )


// BASIC ITERATION

#define PP_ITERATE_0(m, d, ...)
#define PP_ITERATE_1(m, d, ...)  PP_INVOKE( m , ( d , PP_HEAD( __VA_ARGS__ )))
#define PP_ITERATE_2(m, d, ...)  PP_INVOKE( m , ( d , PP_HEAD( __VA_ARGS__ ))) PP_INVOKE( PP_ITERATE_1, ( m, d, PP_TAIL( __VA_ARGS__ )))
#define PP_ITERATE_3(m, d, ...)  PP_INVOKE( m , ( d , PP_HEAD( __VA_ARGS__ ))) PP_INVOKE( PP_ITERATE_2, ( m, d, PP_TAIL( __VA_ARGS__ )))
#define PP_ITERATE_4(m, d, ...)  PP_INVOKE( m , ( d , PP_HEAD( __VA_ARGS__ ))) PP_INVOKE( PP_ITERATE_3, ( m, d, PP_TAIL( __VA_ARGS__ )))
#define PP_ITERATE_5(m, d, ...)  PP_INVOKE( m , ( d , PP_HEAD( __VA_ARGS__ ))) PP_INVOKE( PP_ITERATE_4, ( m, d, PP_TAIL( __VA_ARGS__ )))
#define PP_ITERATE_6(m, d, ...)  PP_INVOKE( m , ( d , PP_HEAD( __VA_ARGS__ ))) PP_INVOKE( PP_ITERATE_5, ( m, d, PP_TAIL( __VA_ARGS__ )))
#define PP_ITERATE_7(m, d, ...)  PP_INVOKE( m , ( d , PP_HEAD( __VA_ARGS__ ))) PP_INVOKE( PP_ITERATE_6, ( m, d, PP_TAIL( __VA_ARGS__ )))
#define PP_ITERATE_8(m, d, ...)  PP_INVOKE( m , ( d , PP_HEAD( __VA_ARGS__ ))) PP_INVOKE( PP_ITERATE_7, ( m, d, PP_TAIL( __VA_ARGS__ )))
#define PP_ITERATE_9(m, d, ...)  PP_INVOKE( m , ( d , PP_HEAD( __VA_ARGS__ ))) PP_INVOKE( PP_ITERATE_8, ( m, d, PP_TAIL( __VA_ARGS__ )))
#define PP_ITERATE_10(m, d, ...) PP_INVOKE( m , ( d , PP_HEAD( __VA_ARGS__ ))) PP_INVOKE( PP_ITERATE_9, ( m, d, PP_TAIL( __VA_ARGS__ )))
#define PP_ITERATE_11(m, d, ...) PP_INVOKE( m , ( d , PP_HEAD( __VA_ARGS__ ))) PP_INVOKE( PP_ITERATE_10, ( m, d, PP_TAIL( __VA_ARGS__ )))
#define PP_ITERATE_12(m, d, ...) PP_INVOKE( m , ( d , PP_HEAD( __VA_ARGS__ ))) PP_INVOKE( PP_ITERATE_11, ( m, d, PP_TAIL( __VA_ARGS__ )))
#define PP_ITERATE_13(m, d, ...) PP_INVOKE( m , ( d , PP_HEAD( __VA_ARGS__ ))) PP_INVOKE( PP_ITERATE_12, ( m, d, PP_TAIL( __VA_ARGS__ )))
#define PP_ITERATE_14(m, d, ...) PP_INVOKE( m , ( d , PP_HEAD( __VA_ARGS__ ))) PP_INVOKE( PP_ITERATE_13, ( m, d, PP_TAIL( __VA_ARGS__ )))
#define PP_ITERATE_15(m, d, ...) PP_INVOKE( m , ( d , PP_HEAD( __VA_ARGS__ ))) PP_INVOKE( PP_ITERATE_14, ( m, d, PP_TAIL( __VA_ARGS__ )))
#define PP_ITERATE_16(m, d, ...) PP_INVOKE( m , ( d , PP_HEAD( __VA_ARGS__ ))) PP_INVOKE( PP_ITERATE_15, ( m, d, PP_TAIL( __VA_ARGS__ )))
#define PP_ITERATE_17(m, d, ...) PP_INVOKE( m , ( d , PP_HEAD( __VA_ARGS__ ))) PP_INVOKE( PP_ITERATE_16, ( m, d, PP_TAIL( __VA_ARGS__ )))
#define PP_ITERATE_18(m, d, ...) PP_INVOKE( m , ( d , PP_HEAD( __VA_ARGS__ ))) PP_INVOKE( PP_ITERATE_17, ( m, d, PP_TAIL( __VA_ARGS__ )))
#define PP_ITERATE_19(m, d, ...) PP_INVOKE( m , ( d , PP_HEAD( __VA_ARGS__ ))) PP_INVOKE( PP_ITERATE_18, ( m, d, PP_TAIL( __VA_ARGS__ )))
#define PP_ITERATE_20(m, d, ...) PP_INVOKE( m , ( d , PP_HEAD( __VA_ARGS__ ))) PP_INVOKE( PP_ITERATE_19, ( m, d, PP_TAIL( __VA_ARGS__ )))
#define PP_ITERATE_21(m, d, ...) PP_INVOKE( m , ( d , PP_HEAD( __VA_ARGS__ ))) PP_INVOKE( PP_ITERATE_20, ( m, d, PP_TAIL( __VA_ARGS__ )))
#define PP_ITERATE_22(m, d, ...) PP_INVOKE( m , ( d , PP_HEAD( __VA_ARGS__ ))) PP_INVOKE( PP_ITERATE_21, ( m, d, PP_TAIL( __VA_ARGS__ )))
#define PP_ITERATE_23(m, d, ...) PP_INVOKE( m , ( d , PP_HEAD( __VA_ARGS__ ))) PP_INVOKE( PP_ITERATE_22, ( m, d, PP_TAIL( __VA_ARGS__ )))
#define PP_ITERATE_24(m, d, ...) PP_INVOKE( m , ( d , PP_HEAD( __VA_ARGS__ ))) PP_INVOKE( PP_ITERATE_23, ( m, d, PP_TAIL( __VA_ARGS__ )))
#define PP_ITERATE_25(m, d, ...) PP_INVOKE( m , ( d , PP_HEAD( __VA_ARGS__ ))) PP_INVOKE( PP_ITERATE_24, ( m, d, PP_TAIL( __VA_ARGS__ )))
#define PP_ITERATE_26(m, d, ...) PP_INVOKE( m , ( d , PP_HEAD( __VA_ARGS__ ))) PP_INVOKE( PP_ITERATE_25, ( m, d, PP_TAIL( __VA_ARGS__ )))
#define PP_ITERATE_27(m, d, ...) PP_INVOKE( m , ( d , PP_HEAD( __VA_ARGS__ ))) PP_INVOKE( PP_ITERATE_26, ( m, d, PP_TAIL( __VA_ARGS__ )))
#define PP_ITERATE_28(m, d, ...) PP_INVOKE( m , ( d , PP_HEAD( __VA_ARGS__ ))) PP_INVOKE( PP_ITERATE_27, ( m, d, PP_TAIL( __VA_ARGS__ )))
#define PP_ITERATE_29(m, d, ...) PP_INVOKE( m , ( d , PP_HEAD( __VA_ARGS__ ))) PP_INVOKE( PP_ITERATE_28, ( m, d, PP_TAIL( __VA_ARGS__ )))
#define PP_ITERATE_30(m, d, ...) PP_INVOKE( m , ( d , PP_HEAD( __VA_ARGS__ ))) PP_INVOKE( PP_ITERATE_29, ( m, d, PP_TAIL( __VA_ARGS__ )))
#define PP_ITERATE_31(m, d, ...) PP_INVOKE( m , ( d , PP_HEAD( __VA_ARGS__ ))) PP_INVOKE( PP_ITERATE_30, ( m, d, PP_TAIL( __VA_ARGS__ )))
#define PP_ITERATE_32(m, d, ...) PP_INVOKE( m , ( d , PP_HEAD( __VA_ARGS__ ))) PP_INVOKE( PP_ITERATE_31, ( m, d, PP_TAIL( __VA_ARGS__ )))

/*!
   \brief Basic iteration functional macro. Iterate elements with apply \a macro with \a data as first argument and arguments list elment as second argument. Maximum is PP_VA_MAXARGS arguments iterate.
   \param macro iteration modifier, functional macro name with two arguments, where first is \a data and second is iterate item
   \param data data used as first argument of \a macro iteration modifier
   \param __VA_ARGS__ arguments to iterate
   \returns result of \a macro call on every arguments
*/
#define PP_ITERATE(macro, data, ...) PP_VA_FUNC(PP_ITERATE, macro, data, __VA_ARGS__)


// ITERATION MODIFIERS

/*!
   \brief Iteration modifier which returns the element itself unchanged. Use as default macro argument for PP_ITERATE.
   \param data data passed in PP_ITERATE
   \param item iterable item
   \returns \a item
*/
#define PP_ITERATE_ITEM(data, item) item

/*!
   \brief Iteration modifier which returns data argument passed in PP_ITERATE. Use as default macro argument for PP_ITERATE.
   \param data data passed in PP_ITERATE
   \param item iterable item
   \returns \a data
*/
#define PP_ITERATE_ITEM_DATA(data, item) data

/*!
   \brief Iteration modifier used if data argument for PP_ITERATE is functional macro which accept one argument. Returning result of \a macro applied on \a item. Use as default macro argument for PP_ITERATE.
   \param macro functional macro passed as data argument in PP_ITERATE which accept one argument 
   \param item iterable item
   \returns result of \a macro applied on \a item
*/
#define PP_ITERATE_ITEM_MACRO(macro, item) PP_INVOKE( macro, ( item ))

/*!
   \brief Iteration modifier which returns \a item with seporator before \a sep. Use as default macro argument for PP_ITERATE.
   \param sep separating literal, except for comma and parentheses
   \param item iterable item
   \returns \a item with seporator before \a sep
*/
#define PP_ITERATE_ITEM_SEP(sep, item) sep item

/*!
   \brief Iteration modifier which returns result of \a macro applied on \a item with comma before.
   A separate function so that a macro with a symbol does not expand ahead of time, because a comma is a control character.
   Use as default macro argument for PP_ITERATE.
   \param macro functional macro passed as data argument in PP_ITERATE which accept one argument 
   \param item iterable item
   \returns result of \a macro applied on \a item with comma before
*/
#define PP_ITERATE_ITEM_COMMA(macro, item) PP_COMMA PP_INVOKE( macro, ( item ))

/*!
   \brief Iteration modifier which returns the name of the function macro with an open parenthesis before the \a item. Used for reduce realization. Use as default macro argument for PP_ITERATE.
   \param fn data passed in PP_ITERATE as functional macro name
   \param item iterable item
   \returns the name of the function macro with an open parenthesis before the \a item
*/
#define PP_ITERATE_ITEM_FOLDR(fn, item) fn PP_OPEN_PAREN item

/*!
   \brief Iteration modifier which returns close parenthesis with comma before the \a item. Used for reduce realization. Use as default macro argument for PP_ITERATE.
   \param data data passed in PP_ITERATE
   \param item iterable item
   \returns close parenthesis with comma before the \a item
*/
#define PP_ITERATE_ITEM_FOLDL(data, item) PP_COMMA item PP_CLOSE_PAREN


// MAP-REDUCE

/*!
   \brief Strip commas of arguments list. Maximum iterate is PP_VA_MAXARGS arguments.
   \param __VA_ARGS__ arguments list
   \returns arguments list without commas
*/
#define PP_STRIP_COMMAS( ... ) PP_ITERATE(PP_ITERATE_ITEM, _, __VA_ARGS__)

/*!
   \brief A short record of applying a \a macro to each item in the argument list, omitting commas at the same time. Maximum iterate is PP_VA_MAXARGS arguments.
   \param macro functional macro take one argument - arguments list item
   \param __VA_ARGS__ arguments list
   \returns list without commas of result apply \a macro on every item of arguments list
*/
#define PP_STRIP_COMMAS_M(macro, ... ) PP_ITERATE(PP_ITERATE_ITEM_MACRO, macro, __VA_ARGS__)

/*!
   \brief Use \a separator to separating arguments list. Maximum iterate is PP_VA_MAXARGS arguments.
   \param separator separating literal, except for comma and parentheses
   \param __VA_ARGS__ arguments list
   \returns arguments list separated by \a separator
*/
#define PP_SEPARATE_LIST(separator, ...) PP_INVOKE( PP_HEAD, (__VA_ARGS__)) separator PP_ITERATE( PP_ITERATE_ITEM_SEP , separator, PP_INVOKE( PP_VA_TAIL, (__VA_ARGS__) ) )

/*!
   \brief A short record of applying a \a macro to each item in the argument list and separating arguments list with \a separator. Maximum iterate is PP_VA_MAXARGS arguments.
   \param macro functional macro take one argument - arguments list item
   \param separator separating literal, except for comma and parentheses
   \param __VA_ARGS__ arguments list
   \returns list separated by \a separator with results of apply \a macro on every item of arguments list
*/
#define PP_SEPARATE_LIST_M(macro, separator, ... ) PP_INVOKE( macro , (PP_INVOKE( PP_HEAD, (__VA_ARGS__) ))) separator PP_ITERATE( PP_ITERATE_ITEM_MACRO , separator macro , PP_INVOKE( PP_VA_TAIL, (__VA_ARGS__) ) )

/*!
   \brief Apply \a macro to every item of arguments list. Maximum iterate is PP_VA_MAXARGS arguments.
   \param macro functional macro take one argument - arguments list item
   \param __VA_ARGS__ arguments list
   \returns list with commas of result apply \a macro on every item of arguments list
*/
#define PP_MAP(macro, ...) PP_INVOKE( macro , (PP_INVOKE( PP_HEAD, (__VA_ARGS__) ))) PP_COMMA PP_ITERATE( PP_ITERATE_ITEM_COMMA , macro, PP_INVOKE( PP_VA_TAIL, (__VA_ARGS__) ) )

/*!
   \brief Short alias for PP_SEPARATE_LIST_M. Applying a \a macro to each item in the argument list and separating arguments list with \a separator. Maximum iterate is PP_VA_MAXARGS arguments.
   \param macro functional macro take one argument - arguments list item
   \param separator separating literal, except for comma and parentheses
   \param __VA_ARGS__ arguments list
   \returns list separated by \a separator with results of apply \a macro on every item of arguments list
*/
#define PP_MAP_SEP(macro, separator, ... )  PP_INVOKE( PP_SEPARATE_LIST_M, ( macro , separator, __VA_ARGS__ ) )

#define PP_REPEAT_0
#define PP_REPEAT_1
#define PP_REPEAT_2(value, count) PP_INVOKE( macro , value ) PP_COMMA PP_ITERATE( PP_ITERATE_ITEM_DATA , PP_INVOKE( macro , ( value )), PP_INVOKE( PP_VA_GEN_A_N, ( PP_INVOKE( PP_VA_DECREMENT, ( count )) ) ) )
#define PP_REPEAT_3(macro, value, count) PP_INVOKE( macro , value ) PP_COMMA PP_ITERATE( PP_ITERATE_ITEM_DATA , PP_INVOKE( macro , ( value )), PP_INVOKE( PP_VA_GEN_A_N, ( PP_INVOKE( PP_VA_DECREMENT, ( count )) ) ) )
#define PP_REPEAT_4(macro, value, count, seporator) PP_INVOKE( macro , value ) seporator PP_ITERATE( PP_ITERATE_ITEM_DATA , separator PP_INVOKE( macro , ( value )), PP_INVOKE( PP_VA_GEN_A_N, ( PP_INVOKE( PP_VA_DECREMENT, ( count )) ) ) )
/*!
   \brief Repeat some code or value passed in \a value \a count times with applying \a macro to every time and separate with \a separator. Maximum is PP_VA_MAXARGS times.
   \param macro [optional, if 3 agruments (macro, value, count)] functional macro take one argument - \a value
   \param value [if 2 agruments (value, count)] some code or value
   \param count [if 2 agruments (value, count)] times to repeat
   \param separator [optional, if 4 agruments (macro, value, count, seporator)] separating literal, except for comma and parentheses
   \returns Separated by \a separator list of repeated \a value with applyed \a macro
*/
#define PP_REPEAT(...)  PP_VA_FUNC(PP_REPEAT, __VA_ARGS__)

/*!
   \brief Reduce arguments list from end. Maximum recursion is PP_VA_MAXARGS arguments. Example: PP_FOLDL( m, acc, a, b, c )  >>>  m( a, m( b, m( c, acc ) ) )
   \param macro functional macro, binary operator witch take two arguments - accumulator and arguments list item
   \param acc initial accumulator
   \param __VA_ARGS__ arguments list
   \returns result of reduce arguments list from end
*/
#define PP_FOLDR(macro, acc, ...) PP_ITERATE( PP_ITERATE_ITEM_FOLDR , macro , __VA_ARGS__ ) PP_COMMA acc PP_REPEAT( PP_INSERT_CLOSE_PAREN , _ ,  PP_VA_SIZE( __VA_ARGS__ ) ) ) )

/*!
   \brief Reduce arguments list from begin. Maximum recursion is PP_VA_MAXARGS arguments. Example: PP_FOLDR( m, acc, a, b, c )  >>>  m( m( m( acc, a), b), c)
   \param macro functional macro, binary operator witch take two arguments - accumulator and arguments list item
   \param acc initial accumulator
   \param __VA_ARGS__ arguments list
   \returns result of reduce arguments list from begin
*/
#define PP_FOLDL(macro, acc, ...) PP_REPEAT( PP_OPEN_FUNC , macro , PP_VA_SIZE( __VA_ARGS__ ) ) ) acc PP_ITERATE( PP_ITERATE_ITEM_FOLDL , _ , __VA_ARGS__ )

/*!
   \brief Reduce arguments list from begin. Maximum recursion is PP_VA_MAXARGS arguments. Example: PP_FOLDR( m, acc, a, b, c )  >>>  m( m( m( acc, a), b), c)
   \param macro functional macro, binary operator witch take two arguments - accumulator and arguments list item
   \param acc initial accumulator
   \param __VA_ARGS__ arguments list
   \returns result of reduce arguments list from begin
*/
#define PP_REDUCE(macro, acc, ...) PP_INVOKE( PP_FOLDL, (macro, acc, __VA_ARGS__) )

/*!
   \brief Swap pair order
   \param first first argument
   \param second second argument
   \returns list with comma swapped first and second arguments
*/
#define PP_SWAP( first, second ) second PP_COMMA first

/*!
   \brief Reverse arguments list. Maximum size of arguments is PP_VA_MAXARGS.
   \param __VA_ARGS__ arguments list
   \returns arguments list in reversed order
*/
#define PP_REVERSE( ... ) PP_INVOKE( PP_FOLDR, (PP_SWAP, PP_HEAD( __VA_ARGS__ ), PP_TAIL( __VA_ARGS__ )) )

// todo: filter, zip, unzip, zip-repeat
// todo: filter to condition ?

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_MACROS_LIB_FUNCTIONAL_H__