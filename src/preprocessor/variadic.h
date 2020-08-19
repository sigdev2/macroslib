//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_MACROS_LIB_VARIADIC_H__
#define __HAS_MACROS_LIB_VARIADIC_H__

/*! \file variadic.h
    \brief Variadic macros. Loops and conditions.
    
    Depend from:
     - /preprocessor/utils.h
*/

#include "utils.h"

/*!
   \brief Maximum of argument counts in variadic macros. Now is 10.
   \returns number
*/
#define PP_VA_MAXARGS 10


// Internals utils

#define PP_VA_GEN_NUMLIST_0
#define PP_VA_GEN_NUMLIST_1 1
#define PP_VA_GEN_NUMLIST_2 1, 2
#define PP_VA_GEN_NUMLIST_3 1, 2, 3
#define PP_VA_GEN_NUMLIST_4 1, 2, 3, 4
#define PP_VA_GEN_NUMLIST_5 1, 2, 3, 4, 5
#define PP_VA_GEN_NUMLIST_6 1, 2, 3, 4, 5, 6
#define PP_VA_GEN_NUMLIST_7 1, 2, 3, 4, 5, 6, 7
#define PP_VA_GEN_NUMLIST_8 1, 2, 3, 4, 5, 6, 7, 8
#define PP_VA_GEN_NUMLIST_9 1, 2, 3, 4, 5, 6, 7, 8, 9
#define PP_VA_GEN_NUMLIST_10 1, 2, 3, 4, 5, 6, 7, 8, 9, 10

#define PP_VA_GEN_RNUMLIST_0
#define PP_VA_GEN_RNUMLIST_1 1
#define PP_VA_GEN_RNUMLIST_2 2, 1
#define PP_VA_GEN_RNUMLIST_3 3, 2, 1
#define PP_VA_GEN_RNUMLIST_4 4, 3, 2, 1
#define PP_VA_GEN_RNUMLIST_5 5, 4, 3, 2, 1
#define PP_VA_GEN_RNUMLIST_6 6, 5, 4, 3, 2, 1
#define PP_VA_GEN_RNUMLIST_7 7, 6, 5, 4, 3, 2, 1
#define PP_VA_GEN_RNUMLIST_8 8, 7, 6, 5, 4, 3, 2, 1
#define PP_VA_GEN_RNUMLIST_9 9, 8, 7, 6, 5, 4, 3, 2, 1
#define PP_VA_GEN_RNUMLIST_10 10, 9, 8, 7, 6, 5, 4, 3, 2, 1

#define PP_VA_GEN_A_0
#define PP_VA_GEN_A_1 _1
#define PP_VA_GEN_A_2 _1, _2
#define PP_VA_GEN_A_3 _1, _2, _3
#define PP_VA_GEN_A_4 _1, _2, _3, _4
#define PP_VA_GEN_A_5 _1, _2, _3, _4, _5
#define PP_VA_GEN_A_6 _1, _2, _3, _4, _5, _6
#define PP_VA_GEN_A_7 _1, _2, _3, _4, _5, _6, _7
#define PP_VA_GEN_A_8 _1, _2, _3, _4, _5, _6, _7, _8
#define PP_VA_GEN_A_9 _1, _2, _3, _4, _5, _6, _7, _8, _9
#define PP_VA_GEN_A_10 _1, _2, _3, _4, _5, _6, _7, _8, _9, _10

#define PP_VA_GET_POS_10(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, NAME, ...) NAME
#define PP_VA_GET_POS_9(_1, _2, _3, _4, _5, _6, _7, _8, _9, NAME, ...) NAME
#define PP_VA_GET_POS_8(_1, _2, _3, _4, _5, _6, _7, _8, NAME, ...) NAME
#define PP_VA_GET_POS_7(_1, _2, _3, _4, _5, _6, _7, NAME, ...) NAME
#define PP_VA_GET_POS_6(_1, _2, _3, _4, _5, _6, NAME, ...) NAME
#define PP_VA_GET_POS_5(_1, _2, _3, _4, _5, NAME, ...) NAME
#define PP_VA_GET_POS_4(_1, _2, _3, _4, NAME, ...) NAME
#define PP_VA_GET_POS_3(_1, _2, _3, NAME, ...) NAME
#define PP_VA_GET_POS_2(_1, _2, NAME, ...) NAME
#define PP_VA_GET_POS_1(_1, NAME, ...) NAME
#define PP_VA_GET_POS_0(NAME, ...) NAME

#define PP_VA_GET(...) PP_INVOKE( PP_VA_GET_A, (__VA_ARGS__) )
#define PP_VA_GET_A(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, R, ...) R


// VA_LIST

/*!
   \brief Return \a head of arguments list
   \param head head of arguments list.
   \param __VA_ARGS__ tail of arguments list.
   \returns \a head of arguments list.
*/
#define PP_VA_HEAD( head , ... ) head

/*!
   \brief Return tail of arguments list
   \param head head of arguments list.
   \param __VA_ARGS__ tail of arguments list.
   \returns tail of arguments list
*/
#define PP_VA_TAIL( head , ... ) __VA_ARGS__


// VA_SIZE

#define PP_VA_SPEC_A(...)
#define PP_VA_SPEC_B(x) PP_CAT(PP_VA_SPEC_, x)
#define PP_VA_SPEC_N0 PP_VA_GEN_NUMLIST_10

#define PP_VA_SIZE_1N(_,...) PP_VA_GET(__VA_ARGS__, PP_VA_GEN_RNUMLIST_10)
#define PP_VA_SIZE_01(_,x) PP_VA_GET( PP_INVOKE( PP_VA_SPEC_B, PP_INVOKE(PP_VA_SPEC_A, x (N1)) PP_EMPTY (N0)),0,1,1,1,1,1,1,1,1,1,__)

/*!
   \brief Return size of arguments list with maximum size is PP_VA_MAXARGS
   \param __VA_ARGS__ arguments list
   \returns size of arguments list
*/
#define PP_VA_SIZE(...) PP_CAT(PP_VA_SIZE_, PP_VA_GET(__VA_ARGS__,1N,1N,1N,1N,1N,1N,1N,1N,1N,01,_) ) (,__VA_ARGS__)


// VA_FUNC

/*!
   \brief Call functional macro with < \a name >_N, where N is size of arguments list and maximum is PP_VA_MAXARGS
   \param name base functional macro name
   \param __VA_ARGS__ arguments list
   \returns call functional macro
*/
#define PP_VA_FUNC(name, ...) PP_INVOKE(PP_CAT( name##_ , PP_VA_SIZE(__VA_ARGS__)), (__VA_ARGS__))


// VA_GEN_NUMLIST
/*!
   \brief Return numbers list with commas like "1, 2, 3" by size of arguments list with maximum is PP_VA_MAXARGS.
   This macro use for replace real arguments, to displace arguments or numerate arguments
   \param __VA_ARGS__ arguments list
   \returns numbers list with commas
*/
#define PP_VA_GEN_NUMLIST(...) PP_VA_FUNC(PP_VA_GEN_NUMLIST, __VA_ARGS__)
/*!
   \brief Return numbers list with commas like "1, 2, 3" with size \a NUM and maximum is PP_VA_MAXARGS. This macro use for generate lists
   \param NUM size of numebrs list
   \returns numbers list with commas
*/
#define PP_VA_GEN_NUMLIST_N(NUM) PP_CAT(PP_VA_GEN_NUMLIST_, NUM )


// VA_GEN_RNUMLIST
/*!
   \brief Return numbers list in reverse order with commas like "3, 2, 1" by size of arguments list with maximum is PP_VA_MAXARGS.
   This macro use for replace real arguments, to displace arguments or numerate arguments
   \param __VA_ARGS__ arguments list
   \returns numbers list with commas
*/
#define PP_VA_GEN_RNUMLIST(...) PP_VA_FUNC(PP_VA_GEN_RNUMLIST, __VA_ARGS__)
/*!
   \brief Return numbers list in reverse order with commas like "1, 2, 3" with size \a NUM and maximum is PP_VA_MAXARGS. This macro use for generate lists
   \param NUM size of numebrs list
   \returns numbers list with commas
*/
#define PP_VA_GEN_RNUMLIST_N(NUM) PP_CAT(PP_VA_GEN_RNUMLIST_, NUM )


// VA_GEN_A
/*!
   \brief Return list of numeric postfixes for functional macros with commas like "_1, _2, _3" by size of arguments list with maximum is PP_VA_MAXARGS.
   This macro use for generate call list of functional macros.
   \param __VA_ARGS__ arguments list
   \returns list of numeric postfixes with commas
*/
#define PP_VA_GEN_A(...) PP_VA_FUNC(PP_VA_GEN_A, __VA_ARGS__)
/*!
   \brief Return list of numeric postfixes for functional macros with commas like "_1, _2, _3" with size \a NUM and maximum is PP_VA_MAXARGS.
   This macro use for generate call list of functional macros.
   \param NUM size of postfixes list
   \returns list of numeric postfixes with commas
*/
#define PP_VA_GEN_A_N(NUM) PP_CAT(PP_VA_GEN_A_, NUM )


// VA_FOR
/*!
   \brief Applay \a macro with \a data as first argument to every item of last arguments list as second argument. Maximum is PP_VA_MAXARGS arguments iterate.
   \param macro macro name
   \param data data used as first argument of \a macro
   \param __VA_ARGS__ arguments to iterate
   \returns result of \a macro call on every arguments
*/
#define PP_VA_FOR(macro,data,...) PP_INVOKE(PP_CAT(PP_VA_FOR_, PP_VA_SIZE(__VA_ARGS__)), ( macro, data, (__VA_ARGS__) ))
#define PP_VA_FOR_0(m,d,x)
#define PP_VA_FOR_1(m,d,x)  m( d, PP_APPLY(PP_VA_HEAD x) )
#define PP_VA_FOR_2(m,d,x)  m( d, PP_APPLY(PP_VA_HEAD x) )  PP_VA_FOR_1( m, d, (PP_APPLY(PP_VA_TAIL x)))
#define PP_VA_FOR_3(m,d,x)  m( d, PP_APPLY(PP_VA_HEAD x) )  PP_VA_FOR_2( m, d, (PP_APPLY(PP_VA_TAIL x)))
#define PP_VA_FOR_4(m,d,x)  m( d, PP_APPLY(PP_VA_HEAD x) )  PP_VA_FOR_3( m, d, (PP_APPLY(PP_VA_TAIL x)))
#define PP_VA_FOR_5(m,d,x)  m( d, PP_APPLY(PP_VA_HEAD x) )  PP_VA_FOR_4( m, d, (PP_APPLY(PP_VA_TAIL x)))
#define PP_VA_FOR_6(m,d,x)  m( d, PP_APPLY(PP_VA_HEAD x) )  PP_VA_FOR_5( m, d, (PP_APPLY(PP_VA_TAIL x)))
#define PP_VA_FOR_7(m,d,x)  m( d, PP_APPLY(PP_VA_HEAD x) )  PP_VA_FOR_6( m, d, (PP_APPLY(PP_VA_TAIL x)))
#define PP_VA_FOR_8(m,d,x)  m( d, PP_APPLY(PP_VA_HEAD x) )  PP_VA_FOR_7( m, d, (PP_APPLY(PP_VA_TAIL x)))
#define PP_VA_FOR_9(m,d,x)  m( d, PP_APPLY(PP_VA_HEAD x) )  PP_VA_FOR_8( m, d, (PP_APPLY(PP_VA_TAIL x)))
#define PP_VA_FOR_10(m,d,x) m( d, PP_APPLY(PP_VA_HEAD x) )  PP_VA_FOR_9( m, d, (PP_APPLY(PP_VA_TAIL x)))


// VA_LIST

/*!
   \brief Applay \a macro to every item of next arguments list. Maximum iterate is PP_VA_MAXARGS arguments.
   \param macro macro name
   \param __VA_ARGS__ arguments to iterate
   \returns result of \a macro call on every arguments
*/
#define VA_LIST(macro, ...)  PP_VA_FOR( macro , 0, __VA_ARGS__ ))

/*!
   \brief Return arguments list with commas. Analog PP_APPLY, but with a different meaning
   \param __VA_ARGS__ arguments list
   \returns list of arguments with commas
*/
#define VA_COMMA_LIST(...) __VA_ARGS__

#define VA_SEMICOLON_LIST_ITEM( dummy, head ) head PP_SEMICOLON
/*!
   \brief Return arguments list with semicolon. Maximum list length is PP_VA_MAXARGS.
   \param __VA_ARGS__ arguments list
   \returns list of arguments with semicolon
*/
#define VA_SEMICOLON_LIST(...) PP_INVOKE( VA_LIST, (VA_SEMICOLON_LIST_ITEM, __VA_ARGS__ ) )


// VA_ARGS_LIST

#define VA_ARGS_LIST_ARGS(skip, choose, ...) choose
#define VA_ARGS_LIST_CHOOSER(...) PP_COMMA
/*!
   \brief Return arguments list with commas in parentheses if he not empty, elese - nothong. This use for macros that can take no arguments, like NOEXCEPT for example.
   \param __VA_ARGS__ arguments list
   \returns arguments list with commas in parentheses or nothong
*/
#define VA_ARGS_LIST(...) PP_INVOKE( VA_ARGS_LIST_ARGS, ( PP_INVOKE( VA_ARGS_LIST_CHOOSER PP_VA_HEAD( __VA_ARGS__ ), ()) , ( __VA_ARGS__ )) )


// VA_IF

#define PP_BOOL_TO_VA_1 PP_TRUE
#define PP_BOOL_TO_VA_true PP_TRUE
#define PP_BOOL_TO_VA_True PP_TRUE
#define PP_BOOL_TO_VA_TRUE PP_TRUE
#define PP_BOOL_TO_VA_0 PP_FALSE
#define PP_BOOL_TO_VA_false PP_FALSE
#define PP_BOOL_TO_VA_False PP_FALSE
#define PP_BOOL_TO_VA_FALSE PP_FALSE
#define PP_BOOL_TO_VA_empty PP_FALSE
#define PP_BOOL_TO_VA_Empty PP_FALSE
#define PP_BOOL_TO_VA_EMPTY PP_FALSE
#define PP_BOOL_TO_VA_nan PP_FALSE
#define PP_BOOL_TO_VA_Nan PP_FALSE
#define PP_BOOL_TO_VA_NAN PP_FALSE
#define PP_BOOL_TO_VA_none PP_FALSE
#define PP_BOOL_TO_VA_None PP_FALSE
#define PP_BOOL_TO_VA_NONE PP_FALSE
#define PP_BOOL_TO_VA_void PP_FALSE
#define PP_BOOL_TO_VA_Void PP_FALSE
#define PP_BOOL_TO_VA_VOID PP_FALSE
#define PP_BOOL_TO_VA_ PP_FALSE
/*!
   \brief Convertion some common terms to MacrosLib preprocessor bool value.
   1, true, True, TRUE to PP_TRUE
   and 0, false, False, FALSE, empty, Empty, EMPTY, nan, Nan, NAN, none, None, NONE, void, Void, VOID to PP_FALSE.
   Note - NULL, null, Null, NaN typically is reserved
   \param b common bool like term
   \returns PP_TRUE or PP_FALSE
*/
#define PP_BOOL_TO_VA(b) PP_CAT( PP_BOOL_TO_VA_ , PP_CAT( b ,) )

#define PP_VA_IF_(t, f) f
#define PP_VA_IF_true(t, f) t
/*!
   \brief Return \a t if \a cont is PP_TRUE and \a f if PP_FALSE. Supported common bool like terms, see PP_BOOL_TO_VA
   \param cond preprocessor bool like condition expression
   \param t term if PP_TRUE
   \param f term if PP_FALSE
   \returns \a t or \a f
*/
#define PP_VA_IF(cond, t, f) PP_CAT( PP_VA_IF_ , PP_BOOL_TO_VA( cond )) ( t , f )

/*!
   \brief Convertion PP_TRUE and PP_FALSE to C/C++ bool value
   \param c preprocessor bool like condition expression
   \returns true or false
*/
#define PP_VA_TO_BOOL(c) PP_VA_IF( c , true, false )

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_MACROS_LIB_VARIADIC_H__