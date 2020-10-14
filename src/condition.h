//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_MACROS_LIB_CONDITION_H__
#define __HAS_MACROS_LIB_CONDITION_H__

/*! \file condition.h
    \brief Macros with conditions. Crosslanguage.
    
    Depend from:
     - /utils.h
     - /variadic.h
     - /functional.h
*/


#include "utils.h"
#include "variadic.h"
#include "functional.h"


// BOOL VALUES

/*! 
   \brief Empty literal, replace to nothing. This may use for insert skipped macro argument or return from a macro to be inserted between the name of a function macro and its arguments to allow its call
*/
#define PP_EMPTY

/*! 
   \brief Alias for Empty literal, replace to nothing
*/
#define PP_BLANK PP_EMPTY

/*! 
   \brief Alias for Empty literal, replace to nothing
*/
#define PP_NONE PP_EMPTY

/*! 
   \brief Alias for Empty literal, replace to nothing
*/
#define PP_NAN PP_EMPTY

/*! 
   \brief Alias for Empty literal, replace to nothing
*/
#define PP_NIL PP_EMPTY

/*! 
   \brief Alias for Empty literal, replace to nothing
*/
#define PP_VOID PP_EMPTY

/*! 
   \brief Alias for Empty literal, replace to nothing.
*/
#define PP_FALSE PP_EMPTY

/*! 
   \brief Non empty macros. Base value is boolean true. This can be used to return from a macro that must be inserted between the function macro name and its arguments to prevent it from being called, and invoke an alternate with the postfix 'true'
*/
#define PP_TRUE true

/*!
   \brief Convert any arguments to PP_TRUE
   \param __VA_ARGS__ any
   \returns PP_TRUE
*/
#define PP_TO_TRUE( ... ) PP_TRUE

/*!
   \brief Convert any arguments to PP_FALSE
   \param __VA_ARGS__ any
   \returns PP_FALSE
*/
#define PP_TO_FALSE( ... ) PP_FALSE


// IF

#define PP_BOOL_TO_1 PP_TRUE
#define PP_BOOL_TO_true PP_TRUE
#define PP_BOOL_TO_True PP_TRUE
#define PP_BOOL_TO_TRUE PP_TRUE
#define PP_BOOL_TO_T PP_TRUE
#define PP_BOOL_TO_t PP_TRUE
#define PP_BOOL_TO_0 PP_FALSE
#define PP_BOOL_TO_F PP_FALSE
#define PP_BOOL_TO_f PP_FALSE
#define PP_BOOL_TO_false PP_FALSE
#define PP_BOOL_TO_False PP_FALSE
#define PP_BOOL_TO_FALSE PP_FALSE
#define PP_BOOL_TO_empty PP_FALSE
#define PP_BOOL_TO_Empty PP_FALSE
#define PP_BOOL_TO_EMPTY PP_FALSE
#define PP_BOOL_TO_nil PP_FALSE
#define PP_BOOL_TO_Nil PP_FALSE
#define PP_BOOL_TO_NIL PP_FALSE
#define PP_BOOL_TO_nan PP_FALSE
#define PP_BOOL_TO_Nan PP_FALSE
#define PP_BOOL_TO_NAN PP_FALSE
#define PP_BOOL_TO_none PP_FALSE
#define PP_BOOL_TO_None PP_FALSE
#define PP_BOOL_TO_NONE PP_FALSE
#define PP_BOOL_TO_void PP_FALSE
#define PP_BOOL_TO_Void PP_FALSE
#define PP_BOOL_TO_VOID PP_FALSE
#define PP_BOOL_TO_ PP_FALSE
/*!
   \brief Convertion some common terms to MacrosLib preprocessor bool value.
   1, f, T, true, True, TRUE to PP_TRUE
   and 0, f, F, false, False, FALSE, empty, Empty, EMPTY, nil, Nil, NIL, nan, Nan, NAN, none, None, NONE, void, Void, VOID to PP_FALSE.
   Note - NULL, null, Null, NaN typically is reserved
   \param b common bool like term
   \returns PP_TRUE or PP_FALSE
*/
#define PP_BOOL_TO_PP(b) PP_BOOL_TO_##b

#define PP_IF_(t, f) f
#define PP_IF_true(t, f) t
/*!
   \brief Return \a t if \a cont is PP_TRUE and \a f if PP_FALSE. Supported common bool like terms, see PP_BOOL_TO_VA
   \param cond preprocessor bool like condition expression
   \param t term if PP_TRUE
   \param f term if PP_FALSE
   \returns \a t or \a f
*/
#define PP_IF(cond, t, f) PP_APPLY(PP_CAT( PP_IF_ , PP_BOOL_TO_PP( cond )) ( t , f ))

/*!
   \brief Apply macro \a x to argumens \a y. PP_INVOKE analog for avoid recursion
   \param x functional macro name.
   \param y macro arguments in parentheses.
   \returns call of expanded macro \a x with \a y arguments.
*/
#define PP_FILTER_INVOKE(x, y) PP_APPLY(x y)

/*!
   \brief Iteration modifier which use \a macro applied on \a item with expand parentheses before as condition for PP_IF and return comma leaded \a item if condition true or nothing.
   Use as default macro argument for PP_ITERATE.
   \param macro functional macro passed as data argument in PP_ITERATE which accept one argument and return boolean value for use as condition
   \param item iterable item
   \returns comma leaded \a item if \a macro condition true or nothing.
*/
#define PP_FILTER_PART(macro, item) PP_CAT( PP_ , PP_IF( PP_FILTER_INVOKE( macro , PP_PAREN( item ) ) , COMMA , FALSE) ) PP_IF( PP_FILTER_INVOKE( macro , PP_PAREN( item ) ) , item , )

/*!
   \brief Use \a macro applied on items from arguments list with expand parentheses before as condition. If condition false then item remove from arguments list. Maximum count of arguments list is PP_VA_MAXARGS.
   \param macro functional macro passed as data argument in PP_ITERATE which accept one argument and return boolean value for use as condition
   \param __VA_ARGS__ iterable item
   \returns list with commas without filtred values
*/
#define PP_FILTER(macro, ... ) PP_IF( PP_FILTER_INVOKE( macro , PP_PAREN( PP_APPLY(PP_HEAD ( __VA_ARGS__ )) ) ) , PP_APPLY(PP_HEAD ( __VA_ARGS__ )) , ) PP_ITERATE(PP_FILTER_PART, macro , PP_APPLY( PP_TAIL ( __VA_ARGS__ ) ) )

/*!
   \brief Binary opreator for create one  of condition expression when used in reduce in PP_COND.
   \param first first condition in parentheses.
   \param __VA_ARGS__ arguments to next chain condition list in parentheses.
   \returns condition expression and tail of conditions list
*/
#define PP_COND_PART(first, ...) PP_IF(PP_APPLY(PP_HEAD first), PP_APPLY(PP_TAIL first), __VA_ARGS__)

/*!
   \brief Use as switch-case construction. Every list of arguments is list in parentheses with head as condition and tail as case. Maximum count of arguments list is PP_VA_MAXARGS.
   \param __VA_ARGS__ arguments list of lists with head as condition and tail as case
   \returns first case with true condition or nothing
*/
#define PP_COND( ... ) PP_RREDUCE(PP_REDUCE_FOLDR, PP_COND_PART, __VA_ARGS__, )


// BOOL OPERATORS

/*! 
   \brief AND boolean operator, return PP_TRUE only if \a a and \a b is PP_TRUE
   \param a first boolean value
   \param b second boolean value
   \return boolean value
*/
#define PP_AND(a, b) PP_IF( a , PP_IF( b , PP_TRUE, PP_FALSE), PP_FALSE)

/*! 
   \brief OR boolean operator, return PP_TRUE if \a a or \a b is PP_TRUE
   \param a first boolean value
   \param b second boolean value
   \return boolean value
*/
#define PP_OR(a, b) PP_IF( a , PP_TRUE, PP_IF( b , PP_TRUE, PP_FALSE))

/*! 
   \brief NOT boolean operator, return PP_TRUE if \a x is PP_FALSE
   \param x boolean value
   \return boolean value
*/
#define PP_NOT(x) PP_IF( x , PP_FALSE, PP_TRUE )

/*! 
   \brief XOR boolean operator, return PP_TRUE only if \a a and \a b is not equal 
   \param a first boolean value
   \param b second boolean value
   \return boolean value
*/
#define PP_XOR(a, b) PP_IF( a , PP_IF( b , PP_FALSE, PP_TRUE), PP_IF( b , PP_TRUE, PP_FALSE))

/*! 
   \brief True if all arguments is true 
   \param __VA_ARGS__ boolean values
   \return boolean value
*/
#define PP_ALL( ... ) PP_FOLDL(PP_AND, true, __VA_ARGS__ )

/*! 
   \brief True if at least one argument is true 
   \param __VA_ARGS__ boolean values
   \return boolean value
*/
#define PP_ONE( ... ) PP_FOLDL(PP_OR, false, __VA_ARGS__ )

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_MACROS_LIB_CONDITION_H__