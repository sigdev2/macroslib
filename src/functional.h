//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_MACROS_LIB_FUNCTIONAL_H__
#define __HAS_MACROS_LIB_FUNCTIONAL_H__

/*! \file functional.h
    \brief Functional programming on macros. Crosslanguage.
    
    Depend from:
     - /utils.h
     - /variadic.h
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
   \brief Return head of list in parentheses or not
   \param __VA_ARGS__ list
   \returns head of list
*/
#define PP_HEAD_PAREN( ... ) PP_APPLY(PP_HEAD PP_PAREN( __VA_ARGS__ ))

/*!
   \brief Return tail in parentheses of list in parentheses or not
   \param __VA_ARGS__ list
   \returns tail of list in parentheses
*/
#define PP_TAIL_PAREN( ... ) PP_PAREN( PP_APPLY( PP_TAIL PP_PAREN( __VA_ARGS__ ) ) )

/*!
   \brief Return \a head of arguments list. Lisp style PP_HEAD_PAREN alias
   \param __VA_ARGS__ tail of arguments list.
   \returns \a head of arguments list.
*/
#define PP_CAR( ... ) PP_HEAD_PAREN( __VA_ARGS__ )

/*!
   \brief Return tail of arguments list. Lisp style PP_TAIL_PAREN alias
   \param __VA_ARGS__ tail of arguments list.
   \returns tail of arguments list
*/
#define PP_CDR( ... ) PP_TAIL_PAREN( __VA_ARGS__ )

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
#define PP_CAAR( ... ) PP_CAR( PP_CAR( __VA_ARGS__ ) )
#define PP_CADR( ... ) PP_CDR( PP_CAR( __VA_ARGS__ ) )
#define PP_CDAR( ... ) PP_APPLY( PP_SECOND PP_PAREN( __VA_ARGS__ ) )
#define PP_CDDR( ... ) ( PP_APPLY( PP_TAIL PP_CDR( __VA_ARGS__ ) ) )
#define PP_CAAAR( ... ) PP_CAR( PP_CAAR( __VA_ARGS__ ) )
#define PP_CAADR( ... ) PP_CDR( PP_CAAR( __VA_ARGS__ ) )
#define PP_CADAR( ... ) PP_APPLY( PP_HEAD PP_CADR( __VA_ARGS__ ) )
#define PP_CDAAR( ... ) PP_CAR( PP_CDAR( __VA_ARGS__ ) )
#define PP_CADDR( ... ) ( PP_APPLY( PP_TAIL PP_CADR( __VA_ARGS__ ) ) )
#define PP_CDDAR( ... ) PP_APPLY( PP_THIRD PP_PAREN( __VA_ARGS__ ) )
#define PP_CDADR( ... ) PP_CDR( PP_CDAR( __VA_ARGS__ ) )
#define PP_CDDDR( ... ) ( PP_APPLY( PP_TAIL PP_CDDR( __VA_ARGS__ ) ) )
#define PP_CAAAAR( ... ) PP_CAR( PP_CAAAR( __VA_ARGS__ ) )
#define PP_CDDDDR( ... ) ( PP_APPLY( PP_TAIL PP_CDDDR( __VA_ARGS__ ) ) )
#define PP_CAAADR( ... ) PP_CDR( PP_CAAAR( __VA_ARGS__ ) )
#define PP_CAADAR( ... ) PP_APPLY( PP_HEAD PP_CAADR( __VA_ARGS__ ) )
#define PP_CADAAR( ... ) PP_CAR( PP_CADAR( __VA_ARGS__ ) )
#define PP_CDAAAR( ... ) PP_CAR( PP_CDAAR( __VA_ARGS__ ) )
#define PP_CAADDR( ... ) ( PP_APPLY( PP_TAIL PP_CAADR( __VA_ARGS__ ) ) )
#define PP_CADADR( ... ) PP_CDR( PP_CADAR( __VA_ARGS__ ) )
#define PP_CDADAR( ... ) PP_APPLY( PP_HEAD PP_CDADR( __VA_ARGS__ ) )
#define PP_CADDAR( ... ) PP_APPLY( PP_HEAD PP_CADDR( __VA_ARGS__ ) )
#define PP_CDAADR( ... ) PP_CDR( PP_CDAAR( __VA_ARGS__ ) )
#define PP_CDDAAR( ... ) PP_CAR( PP_CDDAR( __VA_ARGS__ ) )
#define PP_CADDDR( ... ) ( PP_APPLY( PP_TAIL PP_CADDR( __VA_ARGS__ ) ) )
#define PP_CDADDR( ... ) ( PP_APPLY( PP_TAIL PP_CDADR( __VA_ARGS__ ) ) )
#define PP_CDDADR( ... ) PP_CDR( PP_CDDAR( __VA_ARGS__ ) )
#define PP_CDDDAR( ... ) PP_APPLY( PP_FOURTH PP_PAREN( __VA_ARGS__ ) )

/*!
   \brief Return element of arguments list by \a position. Arguments list size must be not greater than PP_VA_MAXARGS
   \param position position from 0 to PP_VA_MAXARGS
   \param __VA_ARGS__ arguments list.
   \returns last element of arguments list
*/
#define PP_TAKE( position , ... ) PP_CAT( PP_VA_GET_POS_ , position ) ( __VA_ARGS__ )

/*!
   \brief Return last element of arguments list. Arguments list must be not more than PP_VA_MAXARGS
   \param __VA_ARGS__ arguments list.
   \returns last element of arguments list
*/
#define PP_LAST( ... ) PP_TAKE( PP_VA_DECREMENT(PP_VA_SIZE( __VA_ARGS__ )), __VA_ARGS__ )

/*!
   \brief Swap order first pair of arguments list
   \param first first argument
   \param second second argument
   \param __VA_ARGS__ arguments list
   \returns list with comma swapped first and second arguments
*/
#define PP_SWAP( first, second, ... ) second PP_COMMA first PP_COMMA __VA_ARGS__


// BASIC ITERATION

#define PP_ITERATE_0(m, d, ...)
#define PP_ITERATE_1(m, d, ...) m ( d , PP_APPLY(PP_HEAD ( __VA_ARGS__ )) )
#define PP_ITERATE_2(m, d, ...) m ( d , PP_APPLY(PP_HEAD ( __VA_ARGS__ )) ) PP_ITERATE_1 ( m, d, PP_APPLY(PP_TAIL ( __VA_ARGS__ )) )
#define PP_ITERATE_3(m, d, ...) m ( d , PP_APPLY(PP_HEAD ( __VA_ARGS__ )) ) PP_ITERATE_2 ( m, d, PP_APPLY(PP_TAIL ( __VA_ARGS__ )) )
#define PP_ITERATE_4(m, d, ...) m ( d , PP_APPLY(PP_HEAD ( __VA_ARGS__ )) ) PP_ITERATE_3 ( m, d, PP_APPLY(PP_TAIL ( __VA_ARGS__ )) )
#define PP_ITERATE_5(m, d, ...) m ( d , PP_APPLY(PP_HEAD ( __VA_ARGS__ )) ) PP_ITERATE_4 ( m, d, PP_APPLY(PP_TAIL( __VA_ARGS__ )) )
#define PP_ITERATE_6(m, d, ...) m ( d , PP_APPLY(PP_HEAD ( __VA_ARGS__ )) ) PP_ITERATE_5 ( m, d, PP_APPLY(PP_TAIL( __VA_ARGS__ )) )
#define PP_ITERATE_7(m, d, ...) m ( d , PP_APPLY(PP_HEAD ( __VA_ARGS__ )) ) PP_ITERATE_6 ( m, d, PP_APPLY(PP_TAIL( __VA_ARGS__ )) )
#define PP_ITERATE_8(m, d, ...) m ( d , PP_APPLY(PP_HEAD ( __VA_ARGS__ )) ) PP_ITERATE_7 ( m, d, PP_APPLY(PP_TAIL( __VA_ARGS__ )) )
#define PP_ITERATE_9(m, d, ...) m ( d , PP_APPLY(PP_HEAD ( __VA_ARGS__ )) ) PP_ITERATE_8 ( m, d, PP_APPLY(PP_TAIL( __VA_ARGS__ )) )
#define PP_ITERATE_10(m, d, ...) m ( d , PP_APPLY(PP_HEAD ( __VA_ARGS__ )) ) PP_ITERATE_9 ( m, d, PP_APPLY(PP_TAIL( __VA_ARGS__ )) )
#define PP_ITERATE_11(m, d, ...) m ( d , PP_APPLY(PP_HEAD ( __VA_ARGS__ )) ) PP_ITERATE_10 ( m, d, PP_APPLY(PP_TAIL( __VA_ARGS__ )) )
#define PP_ITERATE_12(m, d, ...) m ( d , PP_APPLY(PP_HEAD ( __VA_ARGS__ )) ) PP_ITERATE_11 ( m, d, PP_APPLY(PP_TAIL( __VA_ARGS__ )) )
#define PP_ITERATE_13(m, d, ...) m ( d , PP_APPLY(PP_HEAD ( __VA_ARGS__ )) ) PP_ITERATE_12 ( m, d, PP_APPLY(PP_TAIL( __VA_ARGS__ )) )
#define PP_ITERATE_14(m, d, ...) m ( d , PP_APPLY(PP_HEAD ( __VA_ARGS__ )) ) PP_ITERATE_13 ( m, d, PP_APPLY(PP_TAIL( __VA_ARGS__ )) )
#define PP_ITERATE_15(m, d, ...) m ( d , PP_APPLY(PP_HEAD ( __VA_ARGS__ )) ) PP_ITERATE_14 ( m, d, PP_APPLY(PP_TAIL( __VA_ARGS__ )) )
#define PP_ITERATE_16(m, d, ...) m ( d , PP_APPLY(PP_HEAD ( __VA_ARGS__ )) ) PP_ITERATE_15 ( m, d, PP_APPLY(PP_TAIL( __VA_ARGS__ )) )
#define PP_ITERATE_17(m, d, ...) m ( d , PP_APPLY(PP_HEAD ( __VA_ARGS__ )) ) PP_ITERATE_16 ( m, d, PP_APPLY(PP_TAIL( __VA_ARGS__ )) )
#define PP_ITERATE_18(m, d, ...) m ( d , PP_APPLY(PP_HEAD ( __VA_ARGS__ )) ) PP_ITERATE_17 ( m, d, PP_APPLY(PP_TAIL( __VA_ARGS__ )) )
#define PP_ITERATE_19(m, d, ...) m ( d , PP_APPLY(PP_HEAD ( __VA_ARGS__ )) ) PP_ITERATE_18 ( m, d, PP_APPLY(PP_TAIL( __VA_ARGS__ )) )
#define PP_ITERATE_20(m, d, ...) m ( d , PP_APPLY(PP_HEAD ( __VA_ARGS__ )) ) PP_ITERATE_19 ( m, d, PP_APPLY(PP_TAIL( __VA_ARGS__ )) )
#define PP_ITERATE_21(m, d, ...) m ( d , PP_APPLY(PP_HEAD ( __VA_ARGS__ )) ) PP_ITERATE_20 ( m, d, PP_APPLY(PP_TAIL( __VA_ARGS__ )) )
#define PP_ITERATE_22(m, d, ...) m ( d , PP_APPLY(PP_HEAD ( __VA_ARGS__ )) ) PP_ITERATE_21 ( m, d, PP_APPLY(PP_TAIL( __VA_ARGS__ )) )
#define PP_ITERATE_23(m, d, ...) m ( d , PP_APPLY(PP_HEAD ( __VA_ARGS__ )) ) PP_ITERATE_22 ( m, d, PP_APPLY(PP_TAIL( __VA_ARGS__ )) )
#define PP_ITERATE_24(m, d, ...) m ( d , PP_APPLY(PP_HEAD ( __VA_ARGS__ )) ) PP_ITERATE_23 ( m, d, PP_APPLY(PP_TAIL( __VA_ARGS__ )) )
#define PP_ITERATE_25(m, d, ...) m ( d , PP_APPLY(PP_HEAD ( __VA_ARGS__ )) ) PP_ITERATE_24 ( m, d, PP_APPLY(PP_TAIL( __VA_ARGS__ )) )
#define PP_ITERATE_26(m, d, ...) m ( d , PP_APPLY(PP_HEAD ( __VA_ARGS__ )) ) PP_ITERATE_25 ( m, d, PP_APPLY(PP_TAIL( __VA_ARGS__ )) )
#define PP_ITERATE_27(m, d, ...) m ( d , PP_APPLY(PP_HEAD ( __VA_ARGS__ )) ) PP_ITERATE_26 ( m, d, PP_APPLY(PP_TAIL( __VA_ARGS__ )) )
#define PP_ITERATE_28(m, d, ...) m ( d , PP_APPLY(PP_HEAD ( __VA_ARGS__ )) ) PP_ITERATE_27 ( m, d, PP_APPLY(PP_TAIL( __VA_ARGS__ )) )
#define PP_ITERATE_29(m, d, ...) m ( d , PP_APPLY(PP_HEAD ( __VA_ARGS__ )) ) PP_ITERATE_28 ( m, d, PP_APPLY(PP_TAIL( __VA_ARGS__ )) )
#define PP_ITERATE_30(m, d, ...) m ( d , PP_APPLY(PP_HEAD ( __VA_ARGS__ )) ) PP_ITERATE_29 ( m, d, PP_APPLY(PP_TAIL( __VA_ARGS__ )) )
#define PP_ITERATE_31(m, d, ...) m ( d , PP_APPLY(PP_HEAD ( __VA_ARGS__ )) ) PP_ITERATE_30 ( m, d, PP_APPLY(PP_TAIL( __VA_ARGS__ )) )
#define PP_ITERATE_32(m, d, ...) m ( d , PP_APPLY(PP_HEAD ( __VA_ARGS__ )) ) PP_ITERATE_31 ( m, d, PP_APPLY(PP_TAIL( __VA_ARGS__ )) )

/*!
   \brief Basic iteration functional macro. Iterate elements with apply \a macro with \a data as first argument and arguments list elment as second argument. Maximum is PP_VA_MAXARGS arguments iterate.
   \param macro iteration modifier, functional macro name with two arguments, where first is \a data and second is iterate item
   \param data data used as first argument of \a macro iteration modifier
   \param __VA_ARGS__ arguments to iterate
   \returns result of \a macro call on every arguments
*/
#define PP_ITERATE(macro, data, ...) PP_APPLY(PP_CAT( PP_ITERATE_ , PP_VA_SIZE( __VA_ARGS__ )) ( macro, data, __VA_ARGS__ ))


// ITERATION MODIFIERS

/*!
   \brief Iteration modifier which returns the element itself unchanged. Use as default macro argument for PP_ITERATE.
   \param data data passed in PP_ITERATE
   \param item iterable item
   \returns \a item
*/
#define PP_ITERATE_ITEM(data, item) item

/*!
   \brief Iteration modifier which returns \a data argument passed in PP_ITERATE. Use as default macro argument for PP_ITERATE.
   \param data data passed in PP_ITERATE
   \param item iterable item
   \returns \a data
*/
#define PP_ITERATE_ITEM_DATA(data, item) data

/*!
   \brief Iteration modifier which returns comma leaded \a data argument passed in PP_ITERATE. Use as default macro argument for PP_ITERATE.
   \param data data passed in PP_ITERATE
   \param item iterable item
   \returns comma leaded \a data
*/
#define PP_ITERATE_ITEM_DATA_COMMA(data, item) PP_COMMA data

/*!
   \brief Iteration modifier which use passed to PP_ITERATE data as \a pair where first is functional macro which accept one argument and second is argument for this macro. Use as default macro argument for PP_ITERATE.
   \param pair pair which passed as data in PP_ITERATE, where first is functional macro which accept one argument and second is argument for this macro
   \param item iterable item
   \returns \a pair first aplayed as functional macro on \a pair second
*/
#define PP_ITERATE_ITEM_DATA_PAIR(pair, item) PP_APPLY( PP_CAR( pair ) PP_CDR( pair ) )

/*!
   \brief Iteration modifier which use passed to PP_ITERATE data as \a pair where first is functional macro which accept one argument and second is argument for this macro, result is comma leaded. Use as default macro argument for PP_ITERATE.
   \param pair pair which passed as data in PP_ITERATE, where first is functional macro which accept one argument and second is argument for this macro
   \param item iterable item
   \returns  comma leaded \a pair first aplayed as functional macro on \a pair second
*/
#define PP_ITERATE_ITEM_DATA_PAIR_COMMA(pair, item) PP_COMMA PP_APPLY( PP_CAR( pair ) PP_CDR( pair ) )

/*!
   \brief An iteration modifier that returns comma leaded a comma-separated parenthesized list containing the item passed to PP_ITERATE as \a data appended to the \a item to iterate over. Use as default macro argument for PP_ITERATE.
   \param data data passed in PP_ITERATE
   \param item iterable item
   \returns comma leaded parenthesized list from \a item with appended \a data
*/
#define PP_ITERATE_ITEM_APPEND(data, item) PP_COMMA PP_CAT_PAREN( item , data )

/*!
   \brief An iteration modifier that returns comma leaded a comma-separated parenthesized list containing the item passed to PP_ITERATE as \a data prepended to the \a item to iterate over. Use as default macro argument for PP_ITERATE.
   \param data data passed in PP_ITERATE
   \param item iterable item
   \returns comma leaded parenthesized list from \a item with prepended \a data
*/
#define PP_ITERATE_ITEM_PREPEND(data, item) PP_COMMA PP_CAT_PAREN( data , item )

/*!
   \brief Iteration modifier used if data argument for PP_ITERATE is functional macro which accept one argument. Returning result of \a macro applied on \a item with expand parentheses before. Use as default macro argument for PP_ITERATE.
   \param macro functional macro passed as data argument in PP_ITERATE which accept one argument 
   \param item iterable item
   \returns result of \a macro applied on \a item with expand parentheses before
*/
#define PP_ITERATE_ITEM_MACRO(macro, item) PP_APPLY( macro ( PP_UNPAREN( item )))

/*!
   \brief Iteration modifier which returns \a item with seporator before \a sep. Use as default macro argument for PP_ITERATE.
   \param sep separating literal, except for comma and parentheses
   \param item iterable item
   \returns \a item with seporator before \a sep
*/
#define PP_ITERATE_ITEM_SEP(sep, item) sep item

/*!
   \brief Iteration modifier which returns result of \a macro applied on \a item with expand parentheses before with comma.
   A separate function so that a macro with a symbol does not expand ahead of time, because a comma is a control character.
   Use as default macro argument for PP_ITERATE.
   \param macro functional macro passed as data argument in PP_ITERATE which accept one argument 
   \param item iterable item
   \returns result of \a macro applied on \a item with expand parentheses before with comma
*/
#define PP_ITERATE_ITEM_COMMA(macro, item) PP_COMMA PP_APPLY( macro ( PP_UNPAREN( item )))

/*!
   \brief Iteration modifier which returns the name of the function macro with an open parenthesis before the \a item. Used for reduce realization. Use as default macro argument for PP_ITERATE.
   \param fn data passed in PP_ITERATE as functional macro name
   \param item iterable item
   \returns the name of the function macro with an open parenthesis before the \a item
*/
#define PP_ITERATE_ITEM_FOLDR(fn, item) PP_OPEN_FUNC(fn) item PP_COMMA

/*!
   \brief Iteration modifier which returns close parenthesis with comma before the \a item. Used for reduce realization. Use as default macro argument for PP_ITERATE.
   \param data data passed in PP_ITERATE
   \param item iterable item
   \returns close parenthesis with comma before the \a item
*/
#define PP_ITERATE_ITEM_FOLDL(data, item) PP_COMMA item PP_CLOSE_PAREN


// MAP

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
#define PP_SEPARATE_LIST(separator, ...) PP_APPLY( PP_HEAD (__VA_ARGS__)) PP_ITERATE( PP_ITERATE_ITEM_SEP , separator, PP_APPLY( PP_TAIL (__VA_ARGS__) ) )

/*!
   \brief A short record of applying a \a macro to each item in the argument list and separating arguments list with \a separator. Maximum iterate is PP_VA_MAXARGS arguments.
   \param macro functional macro take one argument - arguments list item
   \param separator separating literal, except for comma and parentheses
   \param __VA_ARGS__ arguments list
   \returns list separated by \a separator with results of apply \a macro on every item of arguments list
*/
#define PP_SEPARATE_LIST_M(macro, separator, ... ) PP_APPLY( macro (PP_APPLY( PP_HEAD (__VA_ARGS__) ))) PP_ITERATE( PP_ITERATE_ITEM_MACRO , separator macro , PP_APPLY( PP_TAIL (__VA_ARGS__) ) )

/*!
   \brief Append \a item to all lists in arguments. Maximum lists count in arguments is PP_VA_MAXARGS.
   \param item item to append
   \param __VA_ARGS__ lists in parentheses
   \returns commed list of lists in parentheses with an \a item appended to each list
*/
#define PP_APPEND_ALL(item, ... )  PP_CAT_PAREN( PP_APPLY( PP_HEAD (__VA_ARGS__) ), item ) PP_ITERATE(PP_ITERATE_ITEM_APPEND, item , PP_APPLY( PP_TAIL (__VA_ARGS__) ) )

/*!
   \brief Prepend \a item to all lists in arguments. Maximum lists count in arguments is PP_VA_MAXARGS.
   \param item item to prepend
   \param __VA_ARGS__ lists in parentheses
   \returns commed list of lists in parentheses with an \a item prepended to each list
*/
#define PP_PREPEND_ALL(item, ... ) PP_CAT_PAREN( PP_APPLY( PP_HEAD (__VA_ARGS__) ), item ) PP_ITERATE(PP_ITERATE_ITEM_PREPEND, item , PP_APPLY( PP_TAIL (__VA_ARGS__) ) )

/*!
   \brief Apply \a macro to every item of arguments list. Maximum iterate is PP_VA_MAXARGS arguments.
   \param macro functional macro take one argument - arguments list item
   \param __VA_ARGS__ arguments list
   \returns list with commas of result apply \a macro on every item of arguments list
*/
#define PP_MAP(macro, ...) PP_APPLY( macro (PP_APPLY( PP_HEAD (__VA_ARGS__) ))) PP_ITERATE( PP_ITERATE_ITEM_COMMA , macro, PP_APPLY( PP_TAIL (__VA_ARGS__) ) )

/*!
   \brief Short alias for PP_SEPARATE_LIST_M. Applying a \a macro to each item in the argument list and separating arguments list with \a separator. Maximum iterate is PP_VA_MAXARGS arguments.
   \param macro functional macro take one argument - arguments list item
   \param separator separating literal, except for comma and parentheses
   \param __VA_ARGS__ arguments list
   \returns list separated by \a separator with results of apply \a macro on every item of arguments list
*/
#define PP_MAP_SEP(macro, separator, ... )  PP_SEPARATE_LIST_M( macro , separator, __VA_ARGS__ )

#define PP_REPEAT_0
#define PP_REPEAT_1
#define PP_REPEAT_2(value, count) value PP_ITERATE( PP_ITERATE_ITEM_DATA_COMMA , value, PP_INVOKE( PP_VA_GEN_A_N, ( PP_VA_DECREMENT( count ) ) ) )
#define PP_REPEAT_3(macro, value, count) PP_APPLY( macro ( value ) ) PP_ITERATE( PP_ITERATE_ITEM_DATA_PAIR_COMMA , ( macro, value ), PP_INVOKE( PP_VA_GEN_A_N, ( PP_VA_DECREMENT( count ) ) ) )
#define PP_REPEAT_4(macro, value, count, separator) PP_APPLY( macro ( value ) ) PP_ITERATE( PP_ITERATE_ITEM_DATA_PAIR , ( separator macro, value ), PP_INVOKE( PP_VA_GEN_A_N, ( PP_VA_DECREMENT( count ) ) ) )
/*!
   \brief Repeat some code or value passed in \a value \a count times with applying \a macro to every time and separate with \a separator.
   Maximum is PP_VA_MAXARGS times. Be careful - the function \a macro is applied every time to every repetition of the \a value - this is necessary for special characters such as commas and parentheses to be processed normally.
   If you do not need to reapply the \a macro, apply it to the \a value before sending it to PP_REPEAT.
   \param macro [optional, if 3 agruments (macro, value, count)] functional macro take one argument - \a value
   \param value [if 2 agruments (value, count)] some code or value
   \param count [if 2 agruments (value, count)] times to repeat
   \param separator [optional, if 4 agruments (macro, value, count, seporator), default is comma] separating literal, except for comma and parentheses
   \returns Separated by \a separator list of repeated \a value with applyed \a macro
*/
#define PP_REPEAT(...)  PP_VA_FUNC(PP_REPEAT, __VA_ARGS__)


// REDUCE

#define PP_REDUCE_0(m, d, ...)
#define PP_REDUCE_1(m, d, ...) PP_APPLY(PP_HEAD ( __VA_ARGS__ ))
#define PP_REDUCE_2(m, d, ...) PP_REDUCE_1( m, d, PP_APPLY(m ( d, __VA_ARGS__ )))
#define PP_REDUCE_3(m, d, ...) PP_REDUCE_2( m, d, PP_APPLY(m ( d, __VA_ARGS__ )))
#define PP_REDUCE_4(m, d, ...) PP_REDUCE_3( m, d, PP_APPLY(m ( d, __VA_ARGS__ )))
#define PP_REDUCE_5(m, d, ...) PP_REDUCE_4( m, d, PP_APPLY(m ( d, __VA_ARGS__ )))
#define PP_REDUCE_6(m, d, ...) PP_REDUCE_5( m, d, PP_APPLY(m ( d, __VA_ARGS__ )))
#define PP_REDUCE_7(m, d, ...) PP_REDUCE_6( m, d, PP_APPLY(m ( d, __VA_ARGS__ )))
#define PP_REDUCE_8(m, d, ...) PP_REDUCE_7( m, d, PP_APPLY(m ( d, __VA_ARGS__ )))
#define PP_REDUCE_9(m, d, ...) PP_REDUCE_8( m, d, PP_APPLY(m ( d, __VA_ARGS__ )))
#define PP_REDUCE_10(m, d, ...) PP_REDUCE_9( m, d, PP_APPLY(m ( d, __VA_ARGS__ )))
#define PP_REDUCE_11(m, d, ...) PP_REDUCE_10( m, d, PP_APPLY(m ( d, __VA_ARGS__ )))
#define PP_REDUCE_12(m, d, ...) PP_REDUCE_11( m, d, PP_APPLY(m ( d, __VA_ARGS__ )))
#define PP_REDUCE_13(m, d, ...) PP_REDUCE_12( m, d, PP_APPLY(m ( d, __VA_ARGS__ )))
#define PP_REDUCE_14(m, d, ...) PP_REDUCE_13( m, d, PP_APPLY(m ( d, __VA_ARGS__ )))
#define PP_REDUCE_15(m, d, ...) PP_REDUCE_14( m, d, PP_APPLY(m ( d, __VA_ARGS__ )))
#define PP_REDUCE_16(m, d, ...) PP_REDUCE_15( m, d, PP_APPLY(m ( d, __VA_ARGS__ )))
#define PP_REDUCE_17(m, d, ...) PP_REDUCE_16( m, d, PP_APPLY(m ( d, __VA_ARGS__ )))
#define PP_REDUCE_18(m, d, ...) PP_REDUCE_17( m, d, PP_APPLY(m ( d, __VA_ARGS__ )))
#define PP_REDUCE_19(m, d, ...) PP_REDUCE_18( m, d, PP_APPLY(m ( d, __VA_ARGS__ )))
#define PP_REDUCE_20(m, d, ...) PP_REDUCE_19( m, d, PP_APPLY(m ( d, __VA_ARGS__ )))
#define PP_REDUCE_21(m, d, ...) PP_REDUCE_20( m, d, PP_APPLY(m ( d, __VA_ARGS__ )))
#define PP_REDUCE_22(m, d, ...) PP_REDUCE_21( m, d, PP_APPLY(m ( d, __VA_ARGS__ )))
#define PP_REDUCE_23(m, d, ...) PP_REDUCE_22( m, d, PP_APPLY(m ( d, __VA_ARGS__ )))
#define PP_REDUCE_24(m, d, ...) PP_REDUCE_23( m, d, PP_APPLY(m ( d, __VA_ARGS__ )))
#define PP_REDUCE_25(m, d, ...) PP_REDUCE_24( m, d, PP_APPLY(m ( d, __VA_ARGS__ )))
#define PP_REDUCE_26(m, d, ...) PP_REDUCE_25( m, d, PP_APPLY(m ( d, __VA_ARGS__ )))
#define PP_REDUCE_27(m, d, ...) PP_REDUCE_26( m, d, PP_APPLY(m ( d, __VA_ARGS__ )))
#define PP_REDUCE_28(m, d, ...) PP_REDUCE_27( m, d, PP_APPLY(m ( d, __VA_ARGS__ )))
#define PP_REDUCE_29(m, d, ...) PP_REDUCE_28( m, d, PP_APPLY(m ( d, __VA_ARGS__ )))
#define PP_REDUCE_30(m, d, ...) PP_REDUCE_29( m, d, PP_APPLY(m ( d, __VA_ARGS__ )))
#define PP_REDUCE_31(m, d, ...) PP_REDUCE_30( m, d, PP_APPLY(m ( d, __VA_ARGS__ )))
#define PP_REDUCE_32(m, d, ...) PP_REDUCE_31( m, d, PP_APPLY(m ( d, __VA_ARGS__ )))
#define PP_REDUCE_33(m, d, ...) PP_REDUCE_32( m, d, PP_APPLY(m ( d, __VA_ARGS__ )))
/*!
   \brief Reduce arguments list with functional \a macro accept \a data, \a accumulator and list of arguments.
   Result of macro is pushed as accumulator and arguments list to next iteration. Maximum recursion is PP_VA_MAXARGS arguments.
   \param macro functional macro, accept \a data, \a accumulator and list of arguments
   \param data data used as first argument of \a macro
   \param accomulator initial accumulator
   \param __VA_ARGS__ arguments list
   \returns result of reduce arguments list from begin
*/
#define PP_REDUCE(macro, data, accomulator, ...) PP_APPLY(PP_CAT( PP_REDUCE_ , PP_VA_SIZE( accomulator , __VA_ARGS__ )) ( macro , data , accomulator , __VA_ARGS__ ))

#define PP_RREDUCE_0(m, d, ...)
#define PP_RREDUCE_1(m, d, ...) __VA_ARGS__
#define PP_RREDUCE_2(m, d, ...) m (d, PP_APPLY(PP_HEAD (__VA_ARGS__)), PP_RREDUCE_1( m, d, PP_APPLY(PP_TAIL (__VA_ARGS__))))
#define PP_RREDUCE_3(m, d, ...) m (d, PP_APPLY(PP_HEAD (__VA_ARGS__)), PP_RREDUCE_2( m, d, PP_APPLY(PP_TAIL (__VA_ARGS__))))
#define PP_RREDUCE_4(m, d, ...) m (d, PP_APPLY(PP_HEAD (__VA_ARGS__)), PP_RREDUCE_3( m, d, PP_APPLY(PP_TAIL (__VA_ARGS__))))
#define PP_RREDUCE_5(m, d, ...) m (d, PP_APPLY(PP_HEAD (__VA_ARGS__)), PP_RREDUCE_4( m, d, PP_APPLY(PP_TAIL (__VA_ARGS__))))
#define PP_RREDUCE_6(m, d, ...) m (d, PP_APPLY(PP_HEAD (__VA_ARGS__)), PP_RREDUCE_5( m, d, PP_APPLY(PP_TAIL (__VA_ARGS__))))
#define PP_RREDUCE_7(m, d, ...) m (d, PP_APPLY(PP_HEAD (__VA_ARGS__)), PP_RREDUCE_6( m, d, PP_APPLY(PP_TAIL (__VA_ARGS__))))
#define PP_RREDUCE_8(m, d, ...) m (d, PP_APPLY(PP_HEAD (__VA_ARGS__)), PP_RREDUCE_7( m, d, PP_APPLY(PP_TAIL (__VA_ARGS__))))
#define PP_RREDUCE_9(m, d, ...) m (d, PP_APPLY(PP_HEAD (__VA_ARGS__)), PP_RREDUCE_8( m, d, PP_APPLY(PP_TAIL (__VA_ARGS__))))
#define PP_RREDUCE_10(m, d, ...) m (d, PP_APPLY(PP_HEAD (__VA_ARGS__)), PP_RREDUCE_9( m, d, PP_APPLY(PP_TAIL (__VA_ARGS__))))
#define PP_RREDUCE_11(m, d, ...) m (d, PP_APPLY(PP_HEAD (__VA_ARGS__)), PP_RREDUCE_10( m, d, PP_APPLY(PP_TAIL (__VA_ARGS__))))
#define PP_RREDUCE_12(m, d, ...) m (d, PP_APPLY(PP_HEAD (__VA_ARGS__)), PP_RREDUCE_11( m, d, PP_APPLY(PP_TAIL (__VA_ARGS__))))
#define PP_RREDUCE_13(m, d, ...) m (d, PP_APPLY(PP_HEAD (__VA_ARGS__)), PP_RREDUCE_12( m, d, PP_APPLY(PP_TAIL (__VA_ARGS__))))
#define PP_RREDUCE_14(m, d, ...) m (d, PP_APPLY(PP_HEAD (__VA_ARGS__)), PP_RREDUCE_13( m, d, PP_APPLY(PP_TAIL (__VA_ARGS__))))
#define PP_RREDUCE_15(m, d, ...) m (d, PP_APPLY(PP_HEAD (__VA_ARGS__)), PP_RREDUCE_14( m, d, PP_APPLY(PP_TAIL (__VA_ARGS__))))
#define PP_RREDUCE_16(m, d, ...) m (d, PP_APPLY(PP_HEAD (__VA_ARGS__)), PP_RREDUCE_15( m, d, PP_APPLY(PP_TAIL (__VA_ARGS__))))
#define PP_RREDUCE_17(m, d, ...) m (d, PP_APPLY(PP_HEAD (__VA_ARGS__)), PP_RREDUCE_16( m, d, PP_APPLY(PP_TAIL (__VA_ARGS__))))
#define PP_RREDUCE_18(m, d, ...) m (d, PP_APPLY(PP_HEAD (__VA_ARGS__)), PP_RREDUCE_17( m, d, PP_APPLY(PP_TAIL (__VA_ARGS__))))
#define PP_RREDUCE_19(m, d, ...) m (d, PP_APPLY(PP_HEAD (__VA_ARGS__)), PP_RREDUCE_18( m, d, PP_APPLY(PP_TAIL (__VA_ARGS__))))
#define PP_RREDUCE_20(m, d, ...) m (d, PP_APPLY(PP_HEAD (__VA_ARGS__)), PP_RREDUCE_19( m, d, PP_APPLY(PP_TAIL (__VA_ARGS__))))
#define PP_RREDUCE_21(m, d, ...) m (d, PP_APPLY(PP_HEAD (__VA_ARGS__)), PP_RREDUCE_20( m, d, PP_APPLY(PP_TAIL (__VA_ARGS__))))
#define PP_RREDUCE_22(m, d, ...) m (d, PP_APPLY(PP_HEAD (__VA_ARGS__)), PP_RREDUCE_21( m, d, PP_APPLY(PP_TAIL (__VA_ARGS__))))
#define PP_RREDUCE_23(m, d, ...) m (d, PP_APPLY(PP_HEAD (__VA_ARGS__)), PP_RREDUCE_22( m, d, PP_APPLY(PP_TAIL (__VA_ARGS__))))
#define PP_RREDUCE_24(m, d, ...) m (d, PP_APPLY(PP_HEAD (__VA_ARGS__)), PP_RREDUCE_23( m, d, PP_APPLY(PP_TAIL (__VA_ARGS__))))
#define PP_RREDUCE_25(m, d, ...) m (d, PP_APPLY(PP_HEAD (__VA_ARGS__)), PP_RREDUCE_24( m, d, PP_APPLY(PP_TAIL (__VA_ARGS__))))
#define PP_RREDUCE_26(m, d, ...) m (d, PP_APPLY(PP_HEAD (__VA_ARGS__)), PP_RREDUCE_25( m, d, PP_APPLY(PP_TAIL (__VA_ARGS__))))
#define PP_RREDUCE_27(m, d, ...) m (d, PP_APPLY(PP_HEAD (__VA_ARGS__)), PP_RREDUCE_26( m, d, PP_APPLY(PP_TAIL (__VA_ARGS__))))
#define PP_RREDUCE_28(m, d, ...) m (d, PP_APPLY(PP_HEAD (__VA_ARGS__)), PP_RREDUCE_27( m, d, PP_APPLY(PP_TAIL (__VA_ARGS__))))
#define PP_RREDUCE_29(m, d, ...) m (d, PP_APPLY(PP_HEAD (__VA_ARGS__)), PP_RREDUCE_28( m, d, PP_APPLY(PP_TAIL (__VA_ARGS__))))
#define PP_RREDUCE_30(m, d, ...) m (d, PP_APPLY(PP_HEAD (__VA_ARGS__)), PP_RREDUCE_29( m, d, PP_APPLY(PP_TAIL (__VA_ARGS__))))
#define PP_RREDUCE_31(m, d, ...) m (d, PP_APPLY(PP_HEAD (__VA_ARGS__)), PP_RREDUCE_30( m, d, PP_APPLY(PP_TAIL (__VA_ARGS__))))
#define PP_RREDUCE_32(m, d, ...) m (d, PP_APPLY(PP_HEAD (__VA_ARGS__)), PP_RREDUCE_31( m, d, PP_APPLY(PP_TAIL (__VA_ARGS__))))
#define PP_RREDUCE_33(m, d, ...) m (d, PP_APPLY(PP_HEAD (__VA_ARGS__)), PP_RREDUCE_32( m, d, PP_APPLY(PP_TAIL (__VA_ARGS__))))
/*!
   \brief Reverse reduce arguments list with functional \a macro accept \a data, list of arguments and accumulator at the end.
   Each next iteration is pushed as third argument to previous macros call when head of list is second angument. Maximum recursion is PP_VA_MAXARGS arguments.
   \param macro functional macro, accept \a data, list of arguments and accumulator at the end.
   \param data data used as first argument of \a macro
   \param __VA_ARGS__ arguments list and accumulator at the end.
   \returns result of reduce arguments list from end
*/
#define PP_RREDUCE(macro, data, ...) PP_APPLY(PP_CAT( PP_RREDUCE_ , PP_VA_SIZE( __VA_ARGS__ )) ( macro , data , __VA_ARGS__ ))

/*!
   \brief Reduce modifier used as \a macro for PP_REDUCE when data argument is functional \a macro, binary operator witch accept two arguments - first accumulator and second arguments list first item.
   Maximum is PP_VA_MAXARGS arguments for fold. Use as default macro argument for PP_REDUCE.
   \param macro functional \a macro, binary operator witch accept two arguments - first accumulator and second arguments list item
   \param acc reduce accumulator
   \param __VA_ARGS__ arguments list
   \returns result of \a macro applied on \a acc and first item of arguments comma separated with tail of arguments list
*/
#define PP_REDUCE_FOLDL(macro, acc, ...) PP_APPLY(macro (acc, PP_APPLY(PP_HEAD ( __VA_ARGS__ )))) PP_COMMA PP_APPLY(PP_TAIL ( __VA_ARGS__ ))

/*!
   \brief Reduce modifier used as \a macro for PP_REDUCE when data argument is list of functional \a macro accept list of arguments in \a acc.
   Maximum is PP_VA_MAXARGS arguments for fold. Use as default macro argument for PP_REDUCE.
   \param macro functional \a macro, binary operator witch accept two arguments - first accumulator and second arguments list item
   \param acc reduce accumulator
   \param __VA_ARGS__ arguments list
   \returns result of \a macro applied on \a acc and first item of arguments comma separated with tail of arguments list
*/
#define PP_REDUCE_COMPOSE(miss, acc, ...) PP_APPLY(PP_APPLY(PP_HEAD ( __VA_ARGS__ )) (PP_UNPAREN(acc))) PP_COMMA PP_APPLY(PP_TAIL ( __VA_ARGS__ ))

/*!
   \brief Reverse reduce modifier used as \a macro for PP_RREDUCE when data argument is functional \a macro, binary operator witch accept two arguments - first is first item of arguments list and second accumulator.
   Maximum is PP_VA_MAXARGS arguments for fold. Use as default macro argument for PP_RREDUCE.
   \param macro functional \a macro, binary operator witch accept two arguments - first is first item of arguments list and second accumulator
   \param __VA_ARGS__ arguments list and last reduce accumulator
   \returns result of \a macro applied on arguments
*/
#define PP_RREDUCE_FOLDR(macro, ...) macro ( __VA_ARGS__ )

/*!
   \brief Reduce arguments list from begin. Maximum recursion is PP_VA_MAXARGS arguments. Example: PP_FOLDR( m, acc, a, b, c )  >>>  m( m( m( acc, a), b), c)
   \param macro functional \a macro, binary operator witch accept two arguments - first accumulator and second arguments list item
   \param acc initial accumulator
   \param __VA_ARGS__ arguments list
   \returns result of reduce arguments list from begin
*/
#define PP_FOLDL(macro, acc, ...) PP_REDUCE( PP_REDUCE_FOLDL, macro , acc, __VA_ARGS__)

/*!
   \brief Reduce arguments list from end. Maximum recursion is PP_VA_MAXARGS arguments. Example: PP_FOLDL( m, acc, a, b, c )  >>>  m( a, m( b, m( c, acc ) ) )
   \param macro functional \a macro, binary operator witch accept two arguments - first is first item of arguments list and second accumulator
   \param acc initial accumulator
   \param __VA_ARGS__ arguments list
   \returns result of reduce arguments list from end
*/
#define PP_FOLDR(macro, acc, ...) PP_RREDUCE( PP_RREDUCE_FOLDR, macro , __VA_ARGS__, acc )

/*!
   \brief Compose applying functional macros. Maximum count PP_VA_MAXARGS functional macros names. Example: a( b( c( \a args ) ) )
   \param args arguments list in parentheses
   \param __VA_ARGS__ list of functional macros names
   \returns result of compose applying functional macrols on \a args
*/
#define PP_COMPOSE(args, ...) PP_REDUCE( PP_REDUCE_COMPOSE , , args, __VA_ARGS__)

/*!
   \brief Compose applying functional macros to every \a list elements. Maximum count of arguments \a list and functional macros names list is PP_VA_MAXARGS. Example: m1( m2( m3( a ) ) ), m1( m2( m3( b ) ) ), m1( m2( m3( c ) ) )
   \param list arguments list in parentheses
   \param __VA_ARGS__ list of functional macros
   \returns list with commas results of compose applying functional macros to every list elements
*/
#define PP_COMPOSE_MAP(list, ...) PP_APPLY(PP_MAP ( PP_COMPOSE, PP_UNPAREN(PP_APPEND_ALL( ( __VA_ARGS__ ) , PP_UNPAREN( list ) ) ) ) )

/*!
   \brief Reverse arguments list. Maximum size of arguments is PP_VA_MAXARGS.
   \param __VA_ARGS__ arguments list
   \returns arguments list in reversed order
*/
#define PP_REVERSE(...) PP_FOLDR(PP_SWAP, __VA_ARGS__ )

/*!
   \brief Binary opreator for store tails list in accumulator when used in reduce. Used in PP_TAILS
   \param acc accumulator to store tails
   \param list list in parentheses
   \param __VA_ARGS__ arguments list
   \returns pair of accumulator with new element and \a list tail
*/
#define PP_TAILS_PART(acc, list, ... ) ( PP_UNPAREN( acc ) PP_COMMA PP_TAIL_PAREN( list ) ) PP_COMMA PP_TAIL_PAREN( list )

/*!
   \brief Generated list with tails of arguments list. Maximum size of arguments is PP_VA_MAXARGS.
   \param __VA_ARGS__ arguments list
   \returns list with tails of arguments list
*/
#define PP_TAILS( ... ) PP_UNPAREN( PP_HEAD( PP_FOLDL(PP_TAILS_PART, ( ( __VA_ARGS__ ) ) PP_COMMA ( __VA_ARGS__ ) , __VA_ARGS__ ) ) )

/*!
   \brief Generates a list of the tails of each list in parentheses in arguments. Maximum size of arguments is PP_VA_MAXARGS.
   \param __VA_ARGS__ arguments list of lists in parentheses 
   \returns tails of each list in parentheses in arguments
*/
#define PP_LISTS_TAILS( ... ) PP_MAP(PP_TAIL_PAREN, __VA_ARGS__)

/*!
   \brief Generates a list of the heads of each list in parentheses in arguments. Maximum size of arguments is PP_VA_MAXARGS.
   \param __VA_ARGS__ arguments list of lists in parentheses 
   \returns heads of each list in parentheses in arguments
*/
#define PP_LISTS_HEADS( ... ) ( PP_MAP(PP_HEAD_PAREN, __VA_ARGS__) )

/*!
   \brief Binary opreator for store piars with elements of two lists in accumulator when used in reduce. Used in PP_ZIP
   \param acc accumulator to store piars with elements of two lists
   \param lists pair of two lists in parentheses
   \param __VA_ARGS__ arguments list
   \returns pair of accumulator with new element and pair with \a lists tails
*/
#define PP_ZIP_PART(acc, lists, ...) ( PP_UNPAREN( acc ) PP_COMMA ( PP_INVOKE( PP_LISTS_HEADS, lists ) ) ) PP_COMMA ( PP_INVOKE( PP_LISTS_TAILS, lists ))

/*!
   \brief Generated list of lists constructed from elements of lists in parentheses from arguments with equals indexes. Length checked by first list. Maximum lists sizes and count of lists is PP_VA_MAXARGS.
   \param __VA_ARGS__ arguments list of lists in parentheses 
   \returns list of lists constructed from elements of lists in parentheses from arguments with equals indexes
*/
#define PP_ZIP(...) PP_UNPAREN( PP_HEAD( PP_FOLDL(PP_ZIP_PART, ( ( PP_INVOKE( PP_LISTS_HEADS, ( __VA_ARGS__ ) ) ) ) PP_COMMA ( PP_INVOKE( PP_LISTS_TAILS, ( __VA_ARGS__ ) ) ) , \
PP_UNPAREN( PP_INVOKE( PP_HEAD, ( __VA_ARGS__ ) ) ) ) ) )

/*!
   \brief Append one item from list of elements to one list from \a lists. Maximum size of lists and elements is PP_VA_MAXARGS. Example: ((), (), ()), a, b, c >>> (a), (b), (c)
   \param lists arguments list of lists in parentheses
   \param __VA_ARGS__ list of elements to append
   \returns list of \a lists with appended by one elements from elements to each list
*/
#define PP_MASS_APPEND( lists, ... ) PP_MAP(PP_CAT_PAREN, PP_ZIP( lists , ( __VA_ARGS__ ) ) )

/*!
   \brief Prepend one item from list of elements to one list from \a lists. Maximum size of lists and elements is PP_VA_MAXARGS. Example: ((), (), ()), a, b, c >>> (a), (b), (c)
   \param lists arguments list of lists in parentheses
   \param __VA_ARGS__ list of elements to prepend
   \returns list of \a lists with prepended by one elements from elements to each list
*/
#define PP_MASS_PREPEND( lists, ... ) PP_MAP(PP_CAT_PAREN, PP_ZIP( ( __VA_ARGS__ ) , lists ) )

/*!
   \brief Unzip list of lists to list with by one item from each list. Maximum size list of lists and items counts in lists is PP_VA_MAXARGS.  Example: (a), (b), (c) >>> a, b, c
   \param __VA_ARGS__ list of lists in parentheses to unzip
   \returns list contains by one item from each list from list of lists
*/
#define PP_UNZIP( first, ... ) PP_INVOKE( PP_FOLDL, (PP_MASS_APPEND, ( PP_REPEAT(PP_INSERT_EMPTY_LIST, _, PP_VA_SIZE( first ) ) ) , first, __VA_ARGS__ ) )

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_MACROS_LIB_FUNCTIONAL_H__
