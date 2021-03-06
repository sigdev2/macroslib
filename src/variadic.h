//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_MACROS_LIB_VARIADIC_H__
#define __HAS_MACROS_LIB_VARIADIC_H__

/*! \file variadic.h
    \brief Variadic macros. Crosslanguage.
    
    Depend from:
     - /utils.h
*/


#include "utils.h"


/*!
   \brief Maximum of argument counts in variadic macros. Now is 32.
   \returns number
*/
#define PP_VA_MAXARGS 32


// Internals consts, defined by PP_VA_MAXARGS

#define PP_VA_GEN_NUMLIST_0
#define PP_VA_GEN_NUMLIST_1 1
#define PP_VA_GEN_NUMLIST_2 PP_VA_GEN_NUMLIST_1, 2
#define PP_VA_GEN_NUMLIST_3 PP_VA_GEN_NUMLIST_2, 3
#define PP_VA_GEN_NUMLIST_4 PP_VA_GEN_NUMLIST_3, 4
#define PP_VA_GEN_NUMLIST_5 PP_VA_GEN_NUMLIST_4, 5
#define PP_VA_GEN_NUMLIST_6 PP_VA_GEN_NUMLIST_5, 6
#define PP_VA_GEN_NUMLIST_7 PP_VA_GEN_NUMLIST_6, 7
#define PP_VA_GEN_NUMLIST_8 PP_VA_GEN_NUMLIST_7, 8
#define PP_VA_GEN_NUMLIST_9 PP_VA_GEN_NUMLIST_8, 9
#define PP_VA_GEN_NUMLIST_10 PP_VA_GEN_NUMLIST_9, 10
#define PP_VA_GEN_NUMLIST_11 PP_VA_GEN_NUMLIST_10, 11
#define PP_VA_GEN_NUMLIST_12 PP_VA_GEN_NUMLIST_11, 12
#define PP_VA_GEN_NUMLIST_13 PP_VA_GEN_NUMLIST_12, 13
#define PP_VA_GEN_NUMLIST_14 PP_VA_GEN_NUMLIST_13, 14
#define PP_VA_GEN_NUMLIST_15 PP_VA_GEN_NUMLIST_14, 15
#define PP_VA_GEN_NUMLIST_16 PP_VA_GEN_NUMLIST_15, 16
#define PP_VA_GEN_NUMLIST_17 PP_VA_GEN_NUMLIST_16, 17
#define PP_VA_GEN_NUMLIST_18 PP_VA_GEN_NUMLIST_17, 18
#define PP_VA_GEN_NUMLIST_19 PP_VA_GEN_NUMLIST_18, 19
#define PP_VA_GEN_NUMLIST_20 PP_VA_GEN_NUMLIST_19, 20
#define PP_VA_GEN_NUMLIST_21 PP_VA_GEN_NUMLIST_20, 21
#define PP_VA_GEN_NUMLIST_22 PP_VA_GEN_NUMLIST_21, 22
#define PP_VA_GEN_NUMLIST_23 PP_VA_GEN_NUMLIST_22, 23
#define PP_VA_GEN_NUMLIST_24 PP_VA_GEN_NUMLIST_23, 24
#define PP_VA_GEN_NUMLIST_25 PP_VA_GEN_NUMLIST_24, 25
#define PP_VA_GEN_NUMLIST_26 PP_VA_GEN_NUMLIST_25, 26
#define PP_VA_GEN_NUMLIST_27 PP_VA_GEN_NUMLIST_26, 27
#define PP_VA_GEN_NUMLIST_28 PP_VA_GEN_NUMLIST_27, 28
#define PP_VA_GEN_NUMLIST_29 PP_VA_GEN_NUMLIST_28, 29
#define PP_VA_GEN_NUMLIST_30 PP_VA_GEN_NUMLIST_29, 30
#define PP_VA_GEN_NUMLIST_31 PP_VA_GEN_NUMLIST_30, 31
#define PP_VA_GEN_NUMLIST_32 PP_VA_GEN_NUMLIST_31, 32

#define PP_VA_GEN_RNUMLIST_0
#define PP_VA_GEN_RNUMLIST_1 1
#define PP_VA_GEN_RNUMLIST_2 2, PP_VA_GEN_RNUMLIST_1
#define PP_VA_GEN_RNUMLIST_3 3, PP_VA_GEN_RNUMLIST_2
#define PP_VA_GEN_RNUMLIST_4 4, PP_VA_GEN_RNUMLIST_3
#define PP_VA_GEN_RNUMLIST_5 5, PP_VA_GEN_RNUMLIST_4
#define PP_VA_GEN_RNUMLIST_6 6, PP_VA_GEN_RNUMLIST_5
#define PP_VA_GEN_RNUMLIST_7 7, PP_VA_GEN_RNUMLIST_6
#define PP_VA_GEN_RNUMLIST_8 8, PP_VA_GEN_RNUMLIST_7
#define PP_VA_GEN_RNUMLIST_9 9, PP_VA_GEN_RNUMLIST_8
#define PP_VA_GEN_RNUMLIST_10 10, PP_VA_GEN_RNUMLIST_9
#define PP_VA_GEN_RNUMLIST_11 11, PP_VA_GEN_RNUMLIST_10
#define PP_VA_GEN_RNUMLIST_12 12, PP_VA_GEN_RNUMLIST_11
#define PP_VA_GEN_RNUMLIST_13 13, PP_VA_GEN_RNUMLIST_12
#define PP_VA_GEN_RNUMLIST_14 14, PP_VA_GEN_RNUMLIST_13
#define PP_VA_GEN_RNUMLIST_15 15, PP_VA_GEN_RNUMLIST_14
#define PP_VA_GEN_RNUMLIST_16 16, PP_VA_GEN_RNUMLIST_15
#define PP_VA_GEN_RNUMLIST_17 17, PP_VA_GEN_RNUMLIST_16
#define PP_VA_GEN_RNUMLIST_18 18, PP_VA_GEN_RNUMLIST_17
#define PP_VA_GEN_RNUMLIST_19 19, PP_VA_GEN_RNUMLIST_18
#define PP_VA_GEN_RNUMLIST_20 20, PP_VA_GEN_RNUMLIST_19
#define PP_VA_GEN_RNUMLIST_21 21, PP_VA_GEN_RNUMLIST_20
#define PP_VA_GEN_RNUMLIST_22 22, PP_VA_GEN_RNUMLIST_21
#define PP_VA_GEN_RNUMLIST_23 23, PP_VA_GEN_RNUMLIST_22
#define PP_VA_GEN_RNUMLIST_24 24, PP_VA_GEN_RNUMLIST_23
#define PP_VA_GEN_RNUMLIST_25 25, PP_VA_GEN_RNUMLIST_24
#define PP_VA_GEN_RNUMLIST_26 26, PP_VA_GEN_RNUMLIST_25
#define PP_VA_GEN_RNUMLIST_27 27, PP_VA_GEN_RNUMLIST_26
#define PP_VA_GEN_RNUMLIST_28 28, PP_VA_GEN_RNUMLIST_27
#define PP_VA_GEN_RNUMLIST_29 29, PP_VA_GEN_RNUMLIST_28
#define PP_VA_GEN_RNUMLIST_30 30, PP_VA_GEN_RNUMLIST_29
#define PP_VA_GEN_RNUMLIST_31 31, PP_VA_GEN_RNUMLIST_30
#define PP_VA_GEN_RNUMLIST_32 32, PP_VA_GEN_RNUMLIST_31

#define PP_VA_GEN_A_0
#define PP_VA_GEN_A_1 _1
#define PP_VA_GEN_A_2 PP_VA_GEN_A_1, _2
#define PP_VA_GEN_A_3 PP_VA_GEN_A_2, _3
#define PP_VA_GEN_A_4 PP_VA_GEN_A_3, _4
#define PP_VA_GEN_A_5 PP_VA_GEN_A_4, _5
#define PP_VA_GEN_A_6 PP_VA_GEN_A_5, _6
#define PP_VA_GEN_A_7 PP_VA_GEN_A_6, _7
#define PP_VA_GEN_A_8 PP_VA_GEN_A_7, _8
#define PP_VA_GEN_A_9 PP_VA_GEN_A_8, _9
#define PP_VA_GEN_A_10 PP_VA_GEN_A_9, _10
#define PP_VA_GEN_A_11 PP_VA_GEN_A_10, _11
#define PP_VA_GEN_A_12 PP_VA_GEN_A_11, _12
#define PP_VA_GEN_A_13 PP_VA_GEN_A_12, _13
#define PP_VA_GEN_A_14 PP_VA_GEN_A_13, _14
#define PP_VA_GEN_A_15 PP_VA_GEN_A_14, _15
#define PP_VA_GEN_A_16 PP_VA_GEN_A_15, _16
#define PP_VA_GEN_A_17 PP_VA_GEN_A_16, _17
#define PP_VA_GEN_A_18 PP_VA_GEN_A_17, _18
#define PP_VA_GEN_A_19 PP_VA_GEN_A_18, _19
#define PP_VA_GEN_A_20 PP_VA_GEN_A_19, _20
#define PP_VA_GEN_A_21 PP_VA_GEN_A_20, _21
#define PP_VA_GEN_A_22 PP_VA_GEN_A_21, _22
#define PP_VA_GEN_A_23 PP_VA_GEN_A_22, _23
#define PP_VA_GEN_A_24 PP_VA_GEN_A_23, _24
#define PP_VA_GEN_A_25 PP_VA_GEN_A_24, _25
#define PP_VA_GEN_A_26 PP_VA_GEN_A_25, _26
#define PP_VA_GEN_A_27 PP_VA_GEN_A_26, _27
#define PP_VA_GEN_A_28 PP_VA_GEN_A_27, _28
#define PP_VA_GEN_A_29 PP_VA_GEN_A_28, _29
#define PP_VA_GEN_A_30 PP_VA_GEN_A_29, _30
#define PP_VA_GEN_A_31 PP_VA_GEN_A_30, _31
#define PP_VA_GEN_A_32 PP_VA_GEN_A_31, _32

#define PP_VA_GET_POS_32(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, NAME, ...) NAME
#define PP_VA_GET_POS_31(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, NAME, ...) NAME
#define PP_VA_GET_POS_30(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, NAME, ...) NAME
#define PP_VA_GET_POS_29(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, NAME, ...) NAME
#define PP_VA_GET_POS_28(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, NAME, ...) NAME
#define PP_VA_GET_POS_27(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, NAME, ...) NAME
#define PP_VA_GET_POS_26(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, NAME, ...) NAME
#define PP_VA_GET_POS_25(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, NAME, ...) NAME
#define PP_VA_GET_POS_24(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, NAME, ...) NAME
#define PP_VA_GET_POS_23(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, NAME, ...) NAME
#define PP_VA_GET_POS_22(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, NAME, ...) NAME
#define PP_VA_GET_POS_21(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, NAME, ...) NAME
#define PP_VA_GET_POS_20(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, NAME, ...) NAME
#define PP_VA_GET_POS_19(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, NAME, ...) NAME
#define PP_VA_GET_POS_18(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, NAME, ...) NAME
#define PP_VA_GET_POS_17(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, NAME, ...) NAME
#define PP_VA_GET_POS_16(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, NAME, ...) NAME
#define PP_VA_GET_POS_15(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, NAME, ...) NAME
#define PP_VA_GET_POS_14(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, NAME, ...) NAME
#define PP_VA_GET_POS_13(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, NAME, ...) NAME
#define PP_VA_GET_POS_12(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, NAME, ...) NAME
#define PP_VA_GET_POS_11(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, NAME, ...) NAME
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

#define PP_VA_SIZE_ZERO_FIRST 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
#define PP_VA_SIZE_CHOOSER 1N, 1N, 1N, 1N, 1N, 1N, 1N, 1N, 1N, 1N, 1N, 1N, 1N, 1N, 1N, 1N, 1N, 1N, 1N, 1N, 1N, 1N, 1N, 1N, 1N, 1N, 1N, 1N, 1N, 1N, 1N, 01

#define PP_VA_GET_A(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, R, ...) R


// VA_GEN_NUMLIST

/*!
   \brief Return numbers list with commas like "1, 2, 3" with size \a NUM and maximum is PP_VA_MAXARGS. This macro use for generate lists
   \param NUM size of numebrs list
   \returns numbers list with commas
*/
#define PP_VA_GEN_NUMLIST_N(NUM) PP_CAT(PP_VA_GEN_NUMLIST_, NUM )

/*!
   \brief Return numbers list in reverse order with commas like "1, 2, 3" with size \a NUM and maximum is PP_VA_MAXARGS. This macro use for generate lists
   \param NUM size of numebrs list
   \returns numbers list with commas
*/
#define PP_VA_GEN_RNUMLIST_N(NUM) PP_CAT(PP_VA_GEN_RNUMLIST_, NUM )

/*!
   \brief Return maximum size numbers list with commas like "1, 2, 3".
   \returns numbers list with commas
*/
#define PP_VA_GEN_NUMLIST_MAX PP_CAT( PP_VA_GEN_NUMLIST_ , PP_VA_MAXARGS )

/*!
   \brief Return maximum size numbers list in reverse order with commas like "1, 2, 3".
   \returns numbers list with commas
*/
#define PP_VA_GEN_RNUMLIST_MAX PP_CAT( PP_VA_GEN_RNUMLIST_ , PP_VA_MAXARGS )


// VA_GET

/*!
   \brief Take argument with position PP_VA_MAXARGS + 1. Use for choose one from PP_VA_MAXARGS variants for arguments list size 
   \param __VA_ARGS__ minimum PP_VA_MAXARGS + 1 arguments list size
   \returns argument with position PP_VA_MAXARGS + 1
*/
#define PP_VA_GET(...) PP_APPLY( PP_VA_GET_A (__VA_ARGS__) )

/*!
   \brief Take choose with \a NUM position from end of chooses list.
   \param NUM position in chooses list, max is PP_VA_MAXARGS
   \param __VA_ARGS__ chooses list with PP_VA_MAXARGS size
   \returns choose with \a NUM position from end of chooses list.
*/
#define PP_VA_GET_N(NUM, ...) PP_VA_GET(PP_VA_GEN_NUMLIST_N(PP_VA_INVERT( NUM )), __VA_ARGS__)


// VA_INVERT

/*!
   \brief Invert number relatively PP_VA_MAXARGS. Result is PP_VA_MAXARGS + 1 - \a NUM
   \param NUM numeric value from 1 to PP_VA_MAXARGS
   \returns inverted \a NUM according to the formula PP_VA_MAXARGS + 1 - \a NUM
*/
#define PP_VA_INVERT(NUM) PP_VA_GET(PP_VA_GEN_NUMLIST_N( NUM ) , PP_VA_GEN_NUMLIST_N( PP_VA_MAXARGS ))


// VA_SIZE

#define PP_VA_SPEC_B(x) PP_CAT(PP_VA_SPEC_, x) ()
#define PP_VA_SPEC_N0() PP_VA_GEN_NUMLIST_MAX

#define PP_VA_SIZE_1N(_,...) PP_VA_GET( __VA_ARGS__, PP_VA_GEN_RNUMLIST_MAX )
#define PP_VA_SIZE_01(_,x) PP_VA_GET( PP_APPLY( PP_VA_SPEC_B PP_REMOVE_INVOKE(x (N1)) (N0) ), PP_VA_SIZE_ZERO_FIRST, __)

/*!
   \brief Return size of arguments list with maximum size is PP_VA_MAXARGS
   \param __VA_ARGS__ arguments list
   \returns size of arguments list
*/
#define PP_VA_SIZE(...) PP_APPLY(PP_CAT(PP_VA_SIZE_, PP_VA_GET( __VA_ARGS__ , PP_VA_SIZE_CHOOSER, _)) (,__VA_ARGS__))

/*!
   \brief Invoke PP_VA_SIZE with expand arguments. Used to avoid recursion with PP_INVOKE
   \param y macro arguments in parentheses.
   \returns code with expanded macro PP_VA_SIZE with \a y as arguments.
*/
#define PP_VA_SIZE_INVOKE(y) PP_APPLY(PP_VA_SIZE y)


// VA_GEN_NUMLIST VARIADIC

/*!
   \brief Return numbers list with commas like "1, 2, 3" by size of arguments list with maximum is PP_VA_MAXARGS.
   This macro use for replace real arguments, to displace arguments or numerate arguments
   \param __VA_ARGS__ arguments list
   \returns numbers list with commas
*/
#define PP_VA_GEN_NUMLIST(...) PP_VA_GEN_NUMLIST_N(PP_VA_SIZE( __VA_ARGS__ ))

/*!
   \brief Return numbers list in reverse order with commas like "3, 2, 1" by size of arguments list with maximum is PP_VA_MAXARGS.
   This macro use for replace real arguments, to displace arguments or numerate arguments
   \param __VA_ARGS__ arguments list
   \returns numbers list with commas
*/
#define PP_VA_GEN_RNUMLIST(...) PP_VA_GEN_RNUMLIST_N(PP_VA_SIZE( __VA_ARGS__ ))


// VA_FUNC

/*!
   \brief Call functional macro with < \a name >_N, where N is size of arguments list and maximum is PP_VA_MAXARGS
   \param name base functional macro name
   \param __VA_ARGS__ arguments list
   \returns call functional macro
*/
#define PP_VA_FUNC(name, ...) PP_APPLY(PP_CAT( PP_CAT( name , _ ) , PP_VA_SIZE( __VA_ARGS__ )) ( __VA_ARGS__ ))


// VA_INCREMENT

/*!
   \brief Return incrementerd \a NUM numeric value, where \a NUM from 0 to PP_VA_MAXARGS
   \param NUM numeric value from 0 to PP_VA_MAXARGS
   \returns incrementerd \a NUM
*/
#define PP_VA_INCREMENT(NUM) PP_INVOKE(PP_CAT(PP_VA_GET_POS_, NUM), (PP_VA_GEN_NUMLIST_N( PP_VA_MAXARGS )))


// VA_DECREMENT

/*!
   \brief Return decremented \a NUM numeric value, where \a NUM from 1 to PP_VA_MAXARGS - 1
   \param NUM numeric value from 1 to PP_VA_MAXARGS - 1
   \returns decremented \a NUM
*/
#define PP_VA_DECREMENT(NUM) PP_INVOKE(PP_CAT(PP_VA_GET_POS_, NUM), (_, 0, PP_VA_GEN_NUMLIST_N( PP_VA_MAXARGS )))


// VA_GEN_A

/*!
   \brief Return list of numeric postfixes for functional macros with commas like "_1, _2, _3" with size \a NUM and maximum is PP_VA_MAXARGS.
   This macro use for generate call list of functional macros.
   \param NUM size of postfixes list
   \returns list of numeric postfixes with commas
*/
#define PP_VA_GEN_A_N(NUM) PP_CAT(PP_VA_GEN_A_, NUM )

/*!
   \brief Invoke PP_VA_GEN_A_N with expand arguments. Used to avoid recursion with PP_INVOKE
   \param y macro arguments in parentheses.
   \returns code with expanded macro PP_VA_GEN_A_N with \a y as arguments.
*/
#define PP_VA_GEN_A_N_INVOKE(y) PP_APPLY(PP_VA_GEN_A_N y)

/*!
   \brief Return list of numeric postfixes for functional macros with commas like "_1, _2, _3" by size of arguments list with maximum is PP_VA_MAXARGS.
   This macro use for generate call list of functional macros.
   \param __VA_ARGS__ arguments list
   \returns list of numeric postfixes with commas
*/
#define PP_VA_GEN_A(...) PP_APPLY(PP_VA_GEN_A_N (PP_VA_SIZE( __VA_ARGS__ )))


// VA_OPT

#define PP_HAS_VA_OPT_CHECK(...) PP_SKIP_OR_CHOOSE(__VA_OPT__(,), , true)
/*!
   \brief Check _VA_OPT_ support
   \returns true or nothing
*/
#define PP_HAS_VA_OPT PP_HAS_VA_OPT_CHECK(?)

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_MACROS_LIB_VARIADIC_H__
