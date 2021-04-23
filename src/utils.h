//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_MACROS_LIB_UTILS_H__
#define __HAS_MACROS_LIB_UTILS_H__

/*! \file utils.h
    \brief Macros for work with preprocessor. Crosslanguage.
*/


// CONTROL LITERALS

/*!
   \brief Comma literal, replace to ','
*/
#define PP_COMMA ,

/*!
   \brief COMMA word, used for construct PP_COMMA macro
*/
#define PP_COMMA_WORD(...) COMMA

/*! 
   \brief Prepending comma to code
   \param __VA_ARGS__ code.
   \returns code with comma before
*/
#define PP_LEAD_COMMA(...) PP_COMMA __VA_ARGS__

/*!
   \brief Functional macro that insert comma if called. Used in macro for skip argument if called.
   Example: PP_INVOKE( PP_INSERT_COMMA TEST_ARG, () ) - insert comma TEST_ARG is empty, else PP_INSERT_COMMA <TEST_ARG> () code
   \param __VA_ARGS__ anything
   \returns comma
*/
#define PP_INSERT_COMMA(...) PP_COMMA

/*!
   \brief PP_ prefix, used for construct macros
*/
#define PP_PREFIX(...) PP_

/*!
   \brief Opening parentheses literal, replace to '('
*/
#define PP_OPEN_PAREN (

/*!
   \brief Closing parentheses literal, replace to ')'
*/
#define PP_CLOSE_PAREN )

/*!
   \brief A functional macro that, when called, inserts a opening parenthesis because it is a control character.
   \param __VA_ARGS__ anything
   \returns opening parentheses literal
*/
#define PP_INSERT_OPEN_PAREN(...) PP_OPEN_PAREN

/*!
   \brief A functional macro that, when called, inserts a closing parenthesis because it is a control character.
   \param __VA_ARGS__ anything
   \returns closing parentheses literal
*/
#define PP_INSERT_CLOSE_PAREN(...) PP_CLOSE_PAREN

/*!
   \brief A functional macro that, when called, inserts a opening and closing parenthesis because it is a control character.
   \param __VA_ARGS__ anything
   \returns opening an closing parentheses literals
*/
#define PP_INSERT_EMPTY_LIST(...) PP_OPEN_PAREN PP_CLOSE_PAREN


// FUNCTIONAL MACROS

/*! 
   \brief Macro which the retrun arguments. Use for expand macros in arguments.
   \param __VA_ARGS__ code with macros.
   \returns code with expanded macros.
*/
#define PP_APPLY(...) __VA_ARGS__

/*!
   \brief Apply macro \a x to argumens \a y. Use for expand macro name from argument and call with expand arguments in other macros.
   To avoid recursion, this macro is best used only in final maсros. For internal macros, it is better to declare a separate macro.
   PP_INVOKE(SUM, (1, 2)) is same as SUM(1, 2)
   \param x functional macro name.
   \param y macro arguments in parentheses.
   \returns call of expanded macro \a x with \a y arguments.
*/
#define PP_INVOKE(x, y) PP_APPLY(x y)

/*!
   \brief Call PP_APPLY macro on argument. Used to apply PP_APPLY macro with avoid recursion with PP_INVOKE
   \param y macro arguments in parentheses.
   \returns code with expanded macro PP_APPLY with \a y as arguments.
*/
#define PP_INVOKE_APPLY(y) PP_APPLY(PP_APPLY y)

/*!
   \brief Simple concat two values in args with ## operator.
   \param x first value.
   \param y second value.
   \returns Concated x and y values
*/
#define PP_CAT_A(x, y) x##y

/*!
   \brief Concat two values in args with two parts:
    - expansion of argument values, even if they are macros, because the preprocessor does not expand on its own for ##
    - call PP_CAT_A with ## operator
   \param x first value.
   \param y second value.
   \returns Concated value of extended \a x and \a y args
*/
#define PP_CAT(x, y) PP_CAT_A(x, y)

/*!
   \brief Invoke PP_CAT with expand arguments. Used to avoid recursion with PP_INVOKE
   \param y macro arguments in parentheses.
   \returns code with expanded macro PP_CAT with \a y as arguments.
*/
#define PP_CAT_INVOKE(y) PP_APPLY(PP_CAT y)

/*!
   \brief Simple convert argument to string.
   \param x value
   \returns \a x value as string in double quotes 
*/
#define PP_STR_A(x) #x

/*!
   \brief Convert argument to string with two parts:
    - expansion of argument values, even if they are macros, because the preprocessor does not expand on its own for #
    - call PP_STR_A with # operator
   \param x value
   \returns Extended \a x value as string in double quotes 
*/
#define PP_STR(x) PP_STR_A(x)

/*!
   \brief Add lead underscore to \a x
   \param x value
   \returns \a x value with lead underscore
*/
#define PP_UNDERSCORE(x) PP_CAT_A(_, x )

/*! 
   \brief Generate code uniq var name like ___some_value_<line_number>
   \returns ___some_value_<line_number>
*/
#define PP_VAR PP_CAT(___some_value_, __LINE__)

/*! 
   \brief Remove code inside. As an example it can be used for translation programs that scan code. PP_REMOVE(TR("SomeTranslateId"))
   \param __VA_ARGS__ code.
   \returns nothing
*/
#define PP_REMOVE(...)

/*!
   \brief Invoke PP_REMOVE with expand arguments. Used to avoid recursion with PP_INVOKE
   \param y macro arguments in parentheses.
   \returns code with expanded macro PP_REMOVE with \a y as arguments.
*/
#define PP_REMOVE_INVOKE(y) PP_APPLY(PP_REMOVE y)

// CHOOSERS

/*!
   \brief Choose argument by \a skip argument use manipulations with commas.
   \param skip argument for skip
   \param choose returned choose
   \param __VA_ARGS__ anything
   \returns choose argument
*/
#define PP_SKIP_OR_CHOOSE(skip, choose, ...) choose

/*!
   \brief Invoke PP_SKIP_OR_CHOOSE with expand arguments. Used to avoid recursion with PP_INVOKE
   \param y macro arguments in parentheses.
   \returns code with expanded macro PP_SKIP_OR_CHOOSE with \a y as arguments.
*/
#define PP_SKIP_OR_CHOOSE_INVOKE(y) PP_APPLY(PP_SKIP_OR_CHOOSE y)

/*!
   \brief Choose last arguments by \a skip first argument use manipulations with commas.
   \param skip argument for skip
   \param __VA_ARGS__ returned choose
   \returns last choosed arguments
*/
#define PP_SKIP_OR_ALL(skip, ...) __VA_ARGS__

/*!
   \brief Invoke PP_SKIP_OR_ALL with expand arguments. Used to avoid recursion with PP_INVOKE
   \param y macro arguments in parentheses.
   \returns code with expanded macro PP_SKIP_OR_ALL with \a y as arguments.
*/
#define PP_SKIP_OR_ALL_INVOKE(y) PP_APPLY(PP_SKIP_OR_ALL y)

/*!
   \brief Choose third argument by skip first and second arguments use manipulations with commas. Use for inverse chooses
   \param _1 argument for skip
   \param _2 argument for skip
   \param choose returned choose
   \param __VA_ARGS__ anything
   \returns choose argument
*/
#define PP_INVERSE_CHOOSE(_1, _2, choose, ...) choose

/*!
   \brief Invoke PP_INVERSE_CHOOSE with expand arguments. Used to avoid recursion with PP_INVOKE
   \param y macro arguments in parentheses.
   \returns code with expanded macro PP_INVERSE_CHOOSE with \a y as arguments.
*/
#define PP_INVERSE_CHOOSE_INVOKE(y) PP_APPLY(PP_INVERSE_CHOOSE y)

/*!
   \brief Choose first argument and skip other.
   \param choose returned choose
   \param _VA_ARGS__ arguments for skip
   \returns choose argument
*/
#define PP_CHOOSE_FIRST(choose, ...) choose

/*!
   \brief Invoke PP_CHOOSE_FIRST with expand arguments. Used to avoid recursion with PP_INVOKE
   \param y macro arguments in parentheses.
   \returns code with expanded macro PP_CHOOSE_FIRST with \a y as arguments.
*/
#define PP_CHOOSE_FIRST_INVOKE(y) PP_APPLY(PP_CHOOSE_FIRST y)


// PARENTHESES MANIPULATIONS

/*!
   \brief Checks if arguments are in parentheses. if yes, it returns a non-empty code, otherwise nothing
   \param arg argument for parentheses test
   \returns non-empty code or nothing
*/
#define PP_IS_IN_PAREN(...) PP_INVERSE_CHOOSE_INVOKE((PP_CAT(PP_ , PP_CHOOSE_FIRST(PP_COMMA_WORD PP_REMOVE __VA_ARGS__ ())), true, ))

/*!
   \brief Wraps the argument list with commas to parentheses. If \a __VA_ARGS__ already in parentheses then is returning not changed. Note this is not just parenthesis wrapping!
   \param __VA_ARGS__ arguments to wrap
   \returns list with commas in parentheses
*/
#define PP_PAREN(...) PP_INVOKE_APPLY(PP_SKIP_OR_CHOOSE_INVOKE((PP_APPLY(PP_INSERT_COMMA PP_IS_IN_PAREN( __VA_ARGS__ ) ()) ((__VA_ARGS__)), (__VA_ARGS__))))

/*!
   \brief Short entry for arguments skip testing.
   If there is at least one non-empty argument, non-empty terms are returned, otherwise a comma is returned. Empty list equal empty value and returning comma
   Used for skip empty arguments in macros.
   \param __VA_ARGS__ test args
   \returns comma or not empty code
*/
#define PP_COMMA_TEST(...) PP_CAT(PP_ , PP_CHOOSE_FIRST_INVOKE((PP_REMOVE_INVOKE(PP_APPLY PP_PAREN(__VA_ARGS__) ()) COMMA)))

/*!
   \brief Checks if arguments are empty. if yes, it returns a non-empty code, otherwise nothing. Empty list equal empty value and returning nothing
   \param __VA_ARGS__ test args
   \returns non-empty code or nothing
*/
#define PP_IS_EMPTY(...) PP_SKIP_OR_CHOOSE_INVOKE((PP_COMMA_TEST(__VA_ARGS__) true, ))

/*!
   \brief Inserting function name and opening parenthesis.
   Used for construct functional macros calls.
   \param __VA_ARGS__ anything
   \returns function name and open parenthesis control literal
*/
#define PP_OPEN_FUNC(name) name PP_OPEN_PAREN

/*!
   \brief Unwraps list with commas in parentheses to list without parentheses. If \a inparen empty, then return nothing
   \param __VA_ARGS__ arguments in parentheses
   \returns list with commas without parentheses or nothing
*/
#define PP_UNPAREN(...) PP_INVOKE_APPLY(PP_PAREN(__VA_ARGS__))

/*!
   \brief Concatenate two lists with commas in parentheses
   \param list1 first list in parentheses
   \param list2 second list in parentheses
   \returns list with commas in parentheses
*/
#define PP_CAT_PAREN(list1, list2) ( PP_UNPAREN(list1) PP_COMMA PP_UNPAREN(list2) )

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_MACROS_LIB_UTILS_H__