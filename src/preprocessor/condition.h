//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_MACROS_LIB_CONDITION_H__
#define __HAS_MACROS_LIB_CONDITION_H__

/*! \file condition.h
    \brief Realization of conditions
    
    Depend from:
     - /preprocessor/utils.h
     - /preprocessor/variadic.h
*/

#include "utils.h"
#include "variadic.h"

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


// IF

#define PP_BOOL_TO_1 PP_TRUE
#define PP_BOOL_TO_true PP_TRUE
#define PP_BOOL_TO_True PP_TRUE
#define PP_BOOL_TO_TRUE PP_TRUE
#define PP_BOOL_TO_T PP_TRUE
#define PP_BOOL_TO_t PP_TRUE
#define PP_BOOL_TO_0 PP_FALSE
#define PP_BOOL_TO_T PP_FALSE
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
#define PP_BOOL_TO_PP(b) PP_CAT( PP_BOOL_TO_ , PP_CAT( b ,) )

#define PP_IF_(t, f) f
#define PP_IF_true(t, f) t
/*!
   \brief Return \a t if \a cont is PP_TRUE and \a f if PP_FALSE. Supported common bool like terms, see PP_BOOL_TO_VA
   \param cond preprocessor bool like condition expression
   \param t term if PP_TRUE
   \param f term if PP_FALSE
   \returns \a t or \a f
*/
#define PP_IF(cond, t, f) PP_CAT( PP_IF_ , PP_BOOL_TO_PP( cond )) ( t , f )

/*!
   \brief Convertion PP_TRUE and PP_FALSE to C/C++ bool value
   \param c preprocessor bool like condition expression
   \returns true or false
*/
#define PP_TO_BOOL(c) PP_IF( c , true, false )

// todo: COND

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

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_MACROS_LIB_CONDITION_H__