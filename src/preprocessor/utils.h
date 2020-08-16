//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_MACROS_LIB_UTILS_H__
#define __HAS_MACROS_LIB_UTILS_H__

/*! \file utils.h
    \brief Macros for work with preprocessor. Crosslanguage.
    
    Depend from:
     - /operators/while.h
*/

#include "../operators/while.h"

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

/*! 
   \brief Semicolon literal, replace to ';'
*/
#define PP_SEMICOLON ;

/*! 
   \brief Comma literal, replace to ','
*/
#define PP_COMMA ,

/*! 
   \brief Empty literal, replace to nothing. This may use for insert skipped macro argument or return from a macro to be inserted between the name of a function macro and its arguments to allow its call
*/
#define PP_EMPTY

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
#define PP_VOID PP_EMPTY

/*! 
   \brief Remove code inside. As an example it can be used for translation programs that scan code. PP_REMOVE(TR("SomeTranslateId"))
   \param __VA_ARGS__ code.
   \returns nothing
*/
#define PP_REMOVE(...)

/*! 
   \brief Non empty macros. Base value is boolean true. This can be used to return from a macro that must be inserted between the function macro name and its arguments to prevent it from being called, and invoke an alternate with the postfix 'true'
*/
#define PP_TRUE true

/*! 
   \brief Alias for Empty literal, replace to nothing.
*/
#define PP_FALSE PP_EMPTY

/*! 
   \brief Macro which the retrun arguments. Use for expand macros in arguments.
   \param __VA_ARGS__ code with macros.
   \returns code with expanded macros.
*/
#define PP_APPLY(...) __VA_ARGS__

/*! 
   \brief Concatenate macros name and argumens. Use for expand macro name from argument and call with expand arguments. PP_INVOKE(SUM, (1, 2)) is same as SUM(1, 2)
   \param x macro name.
   \param y macro arguments in parentheses.
   \returns call of expanded macro with arguments.
*/
#define PP_INVOKE(x, y) PP_APPLY(x y)

/* */
#define PP_FUNC_IF_BRACKETS_PP_HAS_BRACKETS
#define PP_HAS_BRACKETS(...) void (__VA_ARGS__)
#define PP_FUNC_IF_BRACKETS_void void
/*! 
   \brief Determines whether arguments are enclosed in parentheses, if so, converts them to the function type. This is used to convert type lists into a single type.
   \param __VA_ARGS__ type or type list in parentheses.
   \returns type or function type.
*/
#define PP_FUNC_IF_BRACKETS(...) PP_CAT(PP_FUNC_IF_BRACKETS_, PP_HAS_BRACKETS __VA_ARGS__)

/* */
#ifdef __cplusplus

namespace __MacrosLibPrivate
{
    template<typename T> struct single_argument_type { typedef T type; };
    template<typename T, typename U> struct single_argument_type<T(U)> { typedef U type; };
}
/*! 
   \brief [C++] Convert any types or type list to single literal for use in code. This is needed in some macros and templates. May use for inherit classes.
   \param __VA_ARGS__ type or type list in parentheses.
   \returns type literal whithout typename keyword.
*/
#define PP_SINGLE_TYPE_INHERIT(...) __MacrosLibPrivate::single_argument_type< PP_FUNC_IF_BRACKETS(__VA_ARGS__) >::type

/*! 
   \brief [C++] Convert any types or type list to single literal for use in code. This is needed in some macros and templates for passing in parentheses complex types contains commas
   \param __VA_ARGS__ type or type list in parentheses.
   \returns type literal whith typename keyword.
*/
#define PP_SINGLE_TYPE(...) typename __MacrosLibPrivate::single_argument_type< PP_FUNC_IF_BRACKETS(__VA_ARGS__) >::type


#else // !__cplusplus

#define PP_SINGLE_TYPE_INHERIT(...) __VA_ARGS__
#define PP_SINGLE_TYPE(...) __VA_ARGS__

#endif // __cplusplus

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_MACROS_LIB_UTILS_H__