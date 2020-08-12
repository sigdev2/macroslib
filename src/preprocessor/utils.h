//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_MACROS_LIB_UTILS_H__
#define __HAS_MACROS_LIB_UTILS_H__

/*! \file utils.h
    \brief Macroses for work with preprocessor. Crosslanguage.
    
    Depend from:
     - /operators/while.h
*/

#include "../operators/while.h"

/*! 
   \brief Macros for expand indirect macroses. Used for run macros in args of macroses.
   \param m macros name.
   \param args args for macros in brekets.
   \returns Expands to \a m \a args.
*/
#define PP_INDIRECT_EXPAND(m, args) m args

/*! 
   \brief Call code from one or more operators  in args, is anyway converted to one operator.
   \param __VA_ARGS__ code.
   \returns Expands to \a __VA_ARGS__
*/
#define PP_DO_SAFE(...) do { __VA_ARGS__ ; } whileone

/*! 
   \brief Concat two values in args with two parts:
    - expansion of argument values, even if they are macros
    - call PP_CAT_A with ## operator
   \param x first value.
   \param y second value.
   \returns Concat value of extended \a x and \a y args
*/
#define PP_CAT(x, y) PP_CAT_A(x, y)

/*! 
   \brief Simple concat two values in args with ## operator.
   \param x first value.
   \param y second value.
   \returns Concated x and y values
*/
#define PP_CAT_A(x, y) x##y

/*! 
   \brief Generate code uniq var name like ___some_value_<line_number>
   \returns ___some_value_<line_number>
*/
#define PP_VAR PP_CAT(___some_value_, __LINE__)

/*! 
   \brief Call code if bool is true. Use for write short and safe if-operator in macroses.
   \param x bool value.
   \param __VA_ARGS__ code.
   \returns Expands to \a x \a __VA_ARGS__
*/
#define PP_CHECK_IF(x, ...) PP_DO_SAFE(const bool PP_VAR = ( x ); if ( PP_VAR ) { __VA_ARGS__ ; })

#define PP_SEMICOLON ;
#define PP_COMMA ,
#define PP_EMPTY
#define PP_NONE PP_EMPTY
#define PP_NAN PP_EMPTY
#define PP_VOID PP_EMPTY

#define PP_TRUE true
#define PP_FALSE PP_EMPTY

#define PP_APPLY(...) __VA_ARGS__

#define PP_INVOKE(x, y) PP_APPLY(x y)

#define PP_FUNC_IF_BRACKETS_PP_HAS_BRACKETS
#define PP_HAS_BRACKETS(...) void (__VA_ARGS__)
#define PP_FUNC_IF_BRACKETS_void void
#define PP_FUNC_IF_BRACKETS(...) PP_CAT(PP_FUNC_IF_BRACKETS_, PP_HAS_BRACKETS __VA_ARGS__)

#ifdef __cplusplus

namespace __MacrosLibPrivate
{
    template<typename T> struct single_argument_type { typedef T type; };
    template<typename T, typename U> struct single_argument_type<T(U)> { typedef U type; };
}

#define PP_SINGLE_TYPE(...) typename __MacrosLibPrivate::single_argument_type< PP_FUNC_IF_BRACKETS(__VA_ARGS__) >::type
#define PP_SINGLE_TYPE_INHERIT(...) __MacrosLibPrivate::single_argument_type< PP_FUNC_IF_BRACKETS(__VA_ARGS__) >::type

#else // !__cplusplus

#define PP_SINGLE_TYPE(...) __VA_ARGS__
#define PP_SINGLE_TYPE_INHERIT(...) __VA_ARGS__

#endif // __cplusplus

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_MACROS_LIB_UTILS_H__