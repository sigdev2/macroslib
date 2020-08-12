//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_MACROS_LIB_VARIADIC_H__
#define __HAS_MACROS_LIB_VARIADIC_H__

#include "utils.h"

#define PP_VA_MAXARGS 10


// VA_SETS

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


// VA_GET

#define PP_VA_GET(...) PP_INVOKE( PP_VA_GET_A, (__VA_ARGS__) )
#define PP_VA_GET_A(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, R, ...) R


// VA_LIST

#define PP_VA_HEAD(a, ...) a
#define PP_VA_TAIL(a, ...) __VA_ARGS__


// VA_SIZE

#define PP_VA_SPEC_A(...)
#define PP_VA_SPEC_B(x) PP_CAT(PP_VA_SPEC_, x)
#define PP_VA_SPEC_N0 PP_VA_GEN_NUMLIST_10

#define PP_VA_SIZE_1N(_,...) PP_VA_GET(__VA_ARGS__, PP_VA_GEN_RNUMLIST_10)
#define PP_VA_SIZE_01(_,x) PP_VA_GET( PP_INVOKE( PP_VA_SPEC_B, PP_INVOKE(PP_VA_SPEC_A, x (N1)) PP_EMPTY (N0)),0,1,1,1,1,1,1,1,1,1,__)
#define PP_VA_SIZE(...) PP_CAT(PP_VA_SIZE_, PP_VA_GET(__VA_ARGS__,1N,1N,1N,1N,1N,1N,1N,1N,1N,01,_) ) (,__VA_ARGS__)


// VA_FUNC

#define PP_VA_FUNC(name, ...) PP_INVOKE(PP_CAT( name##_ , PP_VA_SIZE(__VA_ARGS__)), (__VA_ARGS__))


// VA_GEN_NUMLIST

#define PP_VA_GEN_NUMLIST(...) PP_VA_FUNC(PP_VA_GEN_NUMLIST, __VA_ARGS__)
#define PP_VA_GEN_NUMLIST_N(NUM) PP_CAT(PP_VA_GEN_NUMLIST_, NUM )


// VA_GEN_RNUMLIST

#define PP_VA_GEN_RNUMLIST(...) PP_VA_FUNC(PP_VA_GEN_RNUMLIST, __VA_ARGS__)
#define PP_VA_GEN_RNUMLIST_N(NUM) PP_CAT(PP_VA_GEN_RNUMLIST_, NUM )


// VA_GEN_A

#define PP_VA_GEN_A(...) PP_VA_FUNC(PP_VA_GEN_A, __VA_ARGS__)
#define PP_VA_GEN_A_N(NUM) PP_CAT(PP_VA_GEN_A_, NUM )


// VA_LAST

#define PP_VA_GET_POS(...) PP_VA_FUNC(PP_VA_GET_POS, __VA_ARGS__)
#define PP_VA_LAST(...) PP_VA_GET_POS(__VA_ARGS__)


// VA_FOR

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

#define VA_LIST(macro, ...)  PP_VA_FOR( macro , 0, __VA_ARGS__ ))

#define VA_COMMA_LIST_ITEM( dummy, head ) PP_COMMA head
#define VA_COMMA_LIST(...) PP_INVOKE( PP_HEAD, ( __VA_ARGS__ ) ) \
                           PP_INVOKE( VA_LIST, (VA_COMMA_LIST_ITEM, PP_INVOKE( PP_TAIL, ( __VA_ARGS__ ) ) ) )

#define VA_SEMICOLON_LIST_ITEM( dummy, head ) head PP_SEMICOLON
#define VA_SEMICOLON_LIST(...) PP_INVOKE( VA_LIST, (VA_SEMICOLON_LIST_ITEM, __VA_ARGS__ ) )


// VA_ARGS_LIST

#define VA_ARGS_LIST_ARGS(skip, choose, ...) choose
#define VA_ARGS_LIST_CHOOSER(...) PP_COMMA
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
#define PP_BOOL_TO_VA(b) PP_CAT( PP_BOOL_TO_VA_ , PP_CAT( b ,) )

#define PP_VA_IF_(t, f) f
#define PP_VA_IF_true(t, f) t
#define PP_VA_IF(cond, t, f) PP_CAT( PP_VA_IF_ , PP_BOOL_TO_VA( cond )) ( t , f )

#define PP_VA_TO_BOOL(c) PP_VA_IF( c , true, false )

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_MACROS_LIB_VARIADIC_H__