#include "../src/utils.h"




PP_IS_IN_PAREN(1) = false
PP_IS_IN_PAREN(1, 2, 3) = false
PP_IS_IN_PAREN((1)) = true
PP_IS_IN_PAREN((1, 2, 3)) = true
PP_IS_IN_PAREN((, 2, 3)) = true
PP_IS_IN_PAREN((, , , , 2, 3)) = true
PP_IS_IN_PAREN((1), 2, 3) = false
PP_IS_IN_PAREN(, 2, 3) = false
PP_IS_IN_PAREN(, , , 1, 2, 3) = false
PP_IS_IN_PAREN((), , , 1, 2, 3) = false
PP_IS_IN_PAREN() = false
PP_IS_IN_PAREN(()) = true

PP_PAREN(1) = (1)
PP_PAREN(1, 2, 3) = (1, 2, 3)
PP_PAREN((1)) = (1)
PP_PAREN((1, 2, 3)) = (1, 2, 3)
PP_PAREN((, 2, 3)) = (, 2, 3)
PP_PAREN((, , , , 2, 3)) = (, , , , 2, 3)
PP_PAREN((1), 2, 3) = ((1), 2, 3)
PP_PAREN(, 2, 3) = (, 2, 3)
PP_PAREN(, , , 1, 2, 3) = (, , , 1, 2, 3)
PP_PAREN((), , , 1, 2, 3) = ((), , , 1, 2, 3)
PP_PAREN() = ()
PP_PAREN(()) = ()

PP_COMMA_TEST(1) = non empty
PP_COMMA_TEST(1, 2, 3) = non empty
PP_COMMA_TEST((1)) = non empty
PP_COMMA_TEST((1, 2, 3)) = non empty
PP_COMMA_TEST((, 2, 3)) = non empty
PP_COMMA_TEST((1), 2, 3) = non empty
PP_COMMA_TEST(, 2, 3) = non empty
PP_COMMA_TEST() = ,
PP_COMMA_TEST(()) = ,

PP_IS_EMPTY(1) = false
PP_IS_EMPTY(1, 2, 3) = false
PP_IS_EMPTY((1)) = false
PP_IS_EMPTY((1, 2, 3)) = false
PP_IS_EMPTY((, 2, 3)) = false
PP_IS_EMPTY((, , , , 2, 3)) = false
PP_IS_EMPTY((1), 2, 3) = false
PP_IS_EMPTY(, 2, 3) = false
PP_IS_EMPTY(, , , 1, 2, 3) = false
PP_IS_EMPTY() = true
PP_IS_EMPTY(()) = true

PP_UNPAREN(1) = 1
PP_UNPAREN((1)) = 1
PP_UNPAREN((1, 2, 3)) = 1, 2, 3
PP_UNPAREN((, 2, 3)) = , 2, 3
PP_UNPAREN() = 
PP_UNPAREN(()) = 

PP_CAT_PAREN((1, 2, 3), (1, 2, 3)) = (1, 2, 3, 1, 2, 3)
PP_CAT_PAREN((1, 2, 3), 4) = (1, 2, 3, 4)
PP_CAT_PAREN(0, (1, 2, 3)) = (0, 1, 2, 3)
PP_CAT_PAREN(0, 1) = (0, 1)