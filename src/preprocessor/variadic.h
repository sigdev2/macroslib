//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_MACROS_LIB_VARIADIC_H__
#define __HAS_MACROS_LIB_VARIADIC_H__

/*! \file variadic.h
    \brief Variadic macros. Operations on arguments list
    
    Depend from:
     - /preprocessor/utils.h
*/

#include "utils.h"

/*!
   \brief Maximum of argument counts in variadic macros. Now is 10.
   \returns number
*/
#define PP_VA_MAXARGS 10


// Internals consts, defined by PP_VA_MAXARGS

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

#define PP_VA_SIZE_ZERO_FIRST 0, 1, 1, 1, 1, 1, 1, 1, 1, 1
#define PP_VA_SIZE_CHOOSER 1N, 1N, 1N, 1N, 1N, 1N, 1N, 1N, 1N, 01

#define PP_VA_GET_A(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, R, ...) R

// VA_GET

/*!
   \brief Take argument with position PP_VA_MAXARGS + 1. Use for choose one from PP_VA_MAXARGS variants for arguments list size 
   \param __VA_ARGS__ minimum PP_VA_MAXARGS + 1 arguments list size
   \returns argument with position PP_VA_MAXARGS + 1
*/
#define PP_VA_GET(...) PP_INVOKE( PP_VA_GET_A, (__VA_ARGS__) )

/*!
   \brief Take choose with \a NUM position from end of chooses list.
   \param NUM position in chooses list, max is PP_VA_MAXARGS
   \param __VA_ARGS__ chooses list with PP_VA_MAXARGS size
   \returns choose with \a NUM position from end of chooses list.
*/
#define PP_VA_GET_N(NUM, ...) PP_VA_GET(PP_INVOKE(PP_CAT, (PP_VA_GEN_NUMLIST_, NUM )), __VA_ARGS__)


// VA_SIZE

#define PP_VA_SPEC_A(...)
#define PP_VA_SPEC_B(x) PP_CAT(PP_VA_SPEC_, x)
#define PP_VA_SPEC_N0 PP_VA_GEN_NUMLIST_10

#define PP_VA_SIZE_1N(_,...) PP_VA_GET(__VA_ARGS__, PP_VA_GEN_RNUMLIST_10)
#define PP_VA_SIZE_01(_,x) PP_VA_GET( PP_INVOKE( PP_VA_SPEC_B, PP_INVOKE(PP_VA_SPEC_A, x (N1)) PP_EMPTY (N0)), PP_VA_SIZE_ZERO_FIRST, __)

/*!
   \brief Return size of arguments list with maximum size is PP_VA_MAXARGS
   \param __VA_ARGS__ arguments list
   \returns size of arguments list
*/
#define PP_VA_SIZE(...) PP_INVOKE(PP_CAT, (PP_VA_SIZE_, PP_VA_GET(__VA_ARGS__, PP_VA_SIZE_CHOOSER, _) )) (,__VA_ARGS__)


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
#define PP_VA_GEN_NUMLIST_N(NUM) PP_INVOKE(PP_CAT, (PP_VA_GEN_NUMLIST_, NUM ))


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


// VA_INCREMENT

/*!
   \brief Return incrementerd \a NUM numeric value, where \a NUM from 0 to PP_VA_MAXARGS
   \param NUM numeric value from 0 to PP_VA_MAXARGS
   \returns incrementerd \a NUM
*/
#define PP_VA_INCREMENT(NUM) PP_VA_GET_N(NUM, _, PP_VA_GEN_RNUMLIST_N( PP_VA_MAXARGS ))


// VA_DECREMENT

/*!
   \brief Return decremented \a NUM numeric value, where \a NUM from 1 to PP_VA_MAXARGS - 1
   \param NUM numeric value from from 1 to PP_VA_MAXARGS - 1
   \returns decremented \a NUM
*/

#define PP_VA_DECREMENT(NUM) PP_VA_GET_N(NUM, PP_VA_GEN_RNUMLIST_N( PP_VA_MAXARGS ), 0)


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
   \brief Apply \a macro with \a data as first argument to every item of last arguments list as second argument. Maximum is PP_VA_MAXARGS arguments iterate.
   \param macro functional macro name with two arguments, where first is \a data and second is iterate item
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

/*!
   \brief Use as default macro argument for PP_VA_FOR which returns the element itself unchanged
   \param data data passed in PP_VA_FOR
   \param item iterable item
   \returns \a item
*/
#define PP_VA_FOR_ITEM(data, item) item

/*!
   \brief Use as default macro argument for PP_VA_FOR which returns data argument passed in PP_VA_FOR
   \param data data passed in PP_VA_FOR
   \param item iterable item
   \returns \a data
*/
#define PP_VA_FOR_ITEM_DATA(data, item) data

/*!
   \brief Use as default macro argument for PP_VA_FOR if data argument for PP_VA_FOR is functional macro which accept one argument. Return \a macro result apply on \a item
   \param macro functional macro passed as data argument in PP_VA_FOR which accept one argument 
   \param item iterable item
   \returns \a macro result apply on \a item
*/
#define PP_VA_FOR_ITEM_MACRO(macro, item) PP_INVOKE( macro, ( item ))

/*!
   \brief Use as default macro argument for PP_VA_FOR if data argument for PP_VA_FOR is functional macro which accept one argument. Return \a macro result apply on \a item and leading is with comma
   \param macro functional macro passed as data argument in PP_VA_FOR which accept one argument 
   \param item iterable item
   \returns comma leaded \a macro result apply on \a item
*/
#define PP_VA_FOR_ITEM_COMMED(macro, item) PP_INVOKE( PP_LEAD_COMMA , ( PP_INVOKE( macro, ( item )) ))

/*!
   \brief Use as default macro argument for PP_VA_FOR if data argument for PP_VA_FOR is functional macro which accept one argument. Return \a macro result apply on \a item and append semicolon
   \param macro functional macro passed as data argument in PP_VA_FOR which accept one argument 
   \param item iterable item
   \returns \a macro result apply on \a item with appended semicolon
*/
#define PP_VA_FOR_ITEM_SEMI(macro, item) PP_INVOKE( PP_APPEND_SEMICOLON , ( PP_INVOKE( macro, ( item )) ))

// VA_LIST

/*!
   \brief Apply \a macro to every item of arguments list. Maximum iterate is PP_VA_MAXARGS arguments.
   \param macro functional macro take one argument - list item
   \param __VA_ARGS__ arguments to iterate
   \returns result of \a macro call on every arguments
*/
#define PP_VA_LIST(macro, ...)  PP_INVOKE( PP_VA_FOR, ( PP_VA_FOR_ITEM_MACRO , macro, __VA_ARGS__ ))

/*!
   \brief Apply \a macro to every item of arguments list and separate commas. Maximum iterate is PP_VA_MAXARGS arguments.
   \param macro functional macro take one argument - list item
   \param __VA_ARGS__ arguments list
   \returns result of \a macro call on every arguments as list with commas
*/
#define PP_VA_COMMA_LIST(macro, ...) PP_INVOKE( macro , (PP_INVOKE( PP_VA_HEAD, (__VA_ARGS__) ))) PP_COMMA PP_INVOKE( PP_VA_FOR, ( PP_VA_FOR_ITEM_COMMED , macro, PP_INVOKE( PP_VA_TAIL, (__VA_ARGS__) ) ))

/*!
   \brief Apply \a macro to every item of arguments list and append semicolon. Maximum iterate is PP_VA_MAXARGS arguments.
   \param macro functional macro take one argument - list item
   \param __VA_ARGS__ arguments list
   \returns result of \a macro call on every arguments as list with separated and ended the semicolon
*/
#define PP_VA_SEMICOLON_LIST(macro, ...) PP_INVOKE( PP_VA_FOR, ( PP_VA_SEMICOLON_LIST_ITEM, macro, __VA_ARGS__ ) )

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_MACROS_LIB_VARIADIC_H__
