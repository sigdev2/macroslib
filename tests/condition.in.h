#include "../src/condition.h"





PP_IF(true, 1, 0) = 1
PP_IF(PP_TRUE, 1, 0) = 1
PP_IF(1, 1, 0) = 1

PP_IF(false, 1, 0) = 0
PP_IF(PP_FALSE, 1, 0) = 0
PP_IF(0, 1, 0) = 0
PP_IF(, 1, 0) = 0

PP_FILTER(PP_TO_TRUE, 1, 2, 3) = 1, 2, 3
PP_FILTER(PP_TO_FALSE, 1, 2, 3) = 

PP_COND((PP_FALSE, 1), (PP_FALSE, 2), (PP_TRUE, 3)) = 3

PP_AND(PP_TRUE, PP_TRUE) = PP_TRUE
PP_AND(PP_TRUE, PP_FALSE) = PP_FALSE
PP_AND(PP_FALSE, PP_TRUE) = PP_FALSE
PP_AND(PP_FALSE, PP_FALSE) = PP_FALSE

PP_OR(PP_TRUE, PP_TRUE) = PP_TRUE
PP_OR(PP_TRUE, PP_FALSE) = PP_TRUE
PP_OR(PP_FALSE, PP_TRUE) = PP_TRUE
PP_OR(PP_FALSE, PP_FALSE) = PP_FALSE 

PP_NOT(PP_TRUE) = PP_FALSE
PP_NOT(PP_FALSE) = PP_TRUE

PP_XOR(PP_TRUE, PP_TRUE) = PP_FALSE
PP_XOR(PP_TRUE, PP_FALSE) = PP_TRUE
PP_XOR(PP_FALSE, PP_TRUE) = PP_TRUE
PP_XOR(PP_FALSE, PP_FALSE) = PP_FALSE 

PP_ALL(PP_TRUE, PP_TRUE, PP_TRUE) = PP_TRUE
PP_ALL(PP_TRUE, PP_FALSE, PP_TRUE) = PP_FALSE

PP_ONE(PP_TRUE, PP_TRUE, PP_TRUE) = PP_TRUE
PP_ONE(PP_TRUE, PP_TRUE, PP_FALSE) = PP_TRUE
PP_ONE(PP_TRUE, PP_FALSE, PP_FALSE) = PP_TRUE
PP_ONE(PP_FALSE, PP_FALSE, PP_FALSE) = PP_FALSE