//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_MACROS_LIB_UTILS_H__
#define __HAS_MACROS_LIB_UTILS_H__

/*! \file utils.h
    \brief Macros for work with preprocessor. Crosslanguage.
*/

/*!
   \brief Simple concat two values in args with ## operator.
   \param x first value.
   \param y second value.
   \returns Concated x and y values
*/
#define PP_CAT_A(x, y) x##y

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
   \brief Generate code uniq var name like ___some_value_<line_number>
   \returns ___some_value_<line_number>
*/
#define PP_VAR PP_CAT(___some_value_, __LINE__)

/*! 
   \brief Semicolon literal, replace to ';'
*/
#define PP_SEMICOLON ;

/*! 
   \brief Append code semicolon literal
   \param __VA_ARGS__ code.
   \returns code ended semicolon literal
*/
#define PP_APPEND_SEMICOLON(...) __VA_ARGS__ PP_SEMICOLON

/*! 
   \brief Comma literal, replace to ','
*/
#define PP_COMMA ,

/*! 
   \brief Leading comma code
   \param __VA_ARGS__ code.
   \returns comma leaded code
*/
#define PP_LEAD_COMMA(...) PP_COMMA __VA_ARGS__

/*!
   \brief Functional macro that insert comma if called. Used in macro for skip argument if called.
   Example: PP_INVOKE( PP_SKIP_COMMA TEST_ARG, () ) - insert comma TEST_ARG is empty, else PP_SKIP_COMMA <TEST_ARG> () code
   \param __VA_ARGS__ anything
   \returns comma or not empty code
*/
#define PP_SKIP_COMMA(...) PP_COMMA

/*! 
   \brief Remove code inside. As an example it can be used for translation programs that scan code. PP_REMOVE(TR("SomeTranslateId"))
   \param __VA_ARGS__ code.
   \returns nothing
*/
#define PP_REMOVE(...)

/*! 
   \brief Macro which the retrun arguments. Use for expand macros in arguments.
   \param __VA_ARGS__ code with macros.
   \returns code with expanded macros.
*/
#define PP_APPLY(...) __VA_ARGS__

/*!
   \brief Concatenate macros name and argumens. Use for expand macro name from argument and call with expand arguments in other macros. PP_INVOKE(SUM, (1, 2)) is same as SUM(1, 2)
   \param x functional macro name.
   \param y macro arguments in parentheses.
   \returns call of expanded macro with arguments.
*/
#define PP_INVOKE(x, y) PP_APPLY(x y)

/*!
   \brief Choose argument by \a skip argument use manipulations with commas. For example use PP_SKIP_COMMA_TEST to return empy \a choose for empty arguments
   \param skip argument for skip
   \param choose returned choose
   \param __VA_ARGS__ anything
   \returns choose argument
*/
#define PP_SKIP_OR_CHOOSE(skip, choose, ...) choose

/*!
   \brief Short entry for arguments skip testing.
   If there is at least \a one non-empty argument then return not empty terms, else return comma.
   If \a one argument non-empty but in parentheses then return nothing (this is implementation specific, since parentheses are control characters).
   Used for skip empty arguments in macros.
   \param one first non-empty argument
   \param __VA_ARGS__ anything
   \returns comma, not empty code or nothing
*/
#define PP_SKIP_COMMA_TEST(one, ...) PP_INVOKE(  PP_SKIP_OR_CHOOSE, (PP_INVOKE( PP_SKIP_COMMA,  one), PP_INVOKE( PP_SKIP_COMMA one, () )) )

/*!
   \brief Wraps the argument list with commas in parentheses. If \a __VA_ARGS__ empty, then return nothing
   \param __VA_ARGS__ arguments to wrap
   \returns wraped list with commas or nothing
*/
#define PP_PAREN(...) PP_INVOKE( PP_SKIP_OR_CHOOSE, (PP_SKIP_COMMA_TEST( __VA_ARGS__ ) , ( __VA_ARGS__ )) )

/*!
   \brief Unwraps list with commas in parentheses to list without parentheses. If \a inparen empty, then return nothing
   \param inparen arguments in parentheses
   \returns list with commas without parentheses or nothing
*/
#define PP_UNPAREN(inparen) PP_SKIP_OR_CHOOSE( PP_LEAD_COMMA inparen , inparen )

/*!
   \brief Concatenate two lists with commas in parentheses
   \param list1 first list in parentheses
   \param list2 second list in parentheses
   \returns list with commas in parentheses
*/
#define PP_CAT_PAREN(list1, list2) PP_PAREN( PP_UNPAREN(list1) PP_COMMA PP_UNPAREN(list2) )

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_MACROS_LIB_UTILS_H__