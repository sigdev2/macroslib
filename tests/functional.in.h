#include "../src/functional.h"





PP_HEAD(1, 2, 3) = 1
PP_TAIL(1, 2, 3) = 2, 3
PP_HEAD_PAREN((1, 2, 3)) = 1
PP_TAIL_PAREN((1, 2, 3)) = (2, 3)

PP_CAR(1, 2, 3) = 1
PP_CDR(1, 2, 3) = ( 2, 3 )

PP_CAR((1, 2, 3)) = 1
PP_CAR((1), 2, 3) = (1)
PP_CDR((1, 2, 3)) = ( 2, 3 )
PP_CDR((1), 2, 3) = ( 2, 3 )

PP_CAAR((1, 2, 3), 2, 3) = 1
PP_CADR((1, 2, 3), 2, 3) = ( 2, 3 )
PP_CDAR(1, 2, 3) = 2
PP_CDDR(1, 2, 3) = ( 3 )
PP_CAAAR(((1, 2, 3), 2, 3), 2, 3) = 1
PP_CAADR(((1, 2, 3), 2, 3), 2, 3) = ( 2, 3 )
PP_CADAR(((1, 2, 3), 2, 3), 2, 3) = 2
PP_CDAAR(1, (1, 2, 3), 3) = 1
PP_CADDR((1, 2, 3), 2, 3) = ( 3 )
PP_CDDAR(1, 2, (1, 2, 3)) = (1, 2, 3)
PP_CDADR(1, (1, 2, 3), 3) = ( 2, 3 )
PP_CDDDR(0, 1, 2, 3) = ( 3 )
PP_CAAAAR((((1, 2, 3), 2, 3), 2, 3), 2, 3) = 1
PP_CDDDDR(0, 1, 2, 3, 4) = ( 4 )
PP_CAAADR((((1, 2, 3), 2, 3), 2, 3), 2, 3) = ( 2, 3 )
PP_CAADAR((((1, 2, 3), 2, 3), 2, 3), 2, 3) = 2
PP_CADAAR((1, (1, 2, 3), 3), 2, 3) = 1
PP_CDAAAR(1, ((1, 2, 3), 2, 3), 3) = 1
PP_CAADDR(((1, 2, 3), 2, 3), 2, 3) = ( 3 ) 
PP_CADADR((1, (1, 2, 3), 3), 2, 3) = ( 2, 3 )
PP_CDADAR(1, (1, 2, 3), 3) = 2
PP_CADDAR((1, 2, 3), 2, 3) = 3
PP_CDAADR(1, ((1, 2, 3), 2, 3), 3) = ( 2, 3 )
PP_CDDAAR(1, 2, ((1, 2, 3), 2, 3)) = (1, 2, 3)
PP_CADDDR((1, 2, 3, 4), 2, 3) = ( 4 )
PP_CDADDR(1, (1, 2, 3), 3) = ( 3 )
PP_CDDADR(1, 2, ((1, 2, 3), 2, 3)) = ( 2, 3 )
PP_CDDDAR(1, 2, 3, (1, 2, 3)) = (1, 2, 3)

PP_FIRST(1, 2, 3, 4) = 1
PP_SECOND(1, 2, 3, 4) = 2
PP_THIRD(1, 2, 3, 4) = 3
PP_FOURTH(1, 2, 3, 4) = 4

PP_TAKE(0, 1, 2, 3, 4, 5) = 1
PP_TAKE(4, 1, 2, 3, 4, 5) = 5

PP_LAST(1, 2, 3, 4, 5, 6) = 6

PP_SWAP(1, 2, 3, 4) = 2, 1, 3, 4

PP_ITERATE(PP_ITERATE_ITEM, ddd, 1, 2, 3) = 1 2 3
PP_ITERATE(PP_ITERATE_ITEM_DATA, ddd, 1, 2, 3) = ddd ddd ddd
PP_ITERATE(PP_ITERATE_ITEM_DATA, ddd, PP_VA_GEN_NUMLIST_MAX) = ddd ddd ddd
PP_ITERATE(PP_ITERATE_ITEM_APPEND, 1, (a, b, c), (a, b, c), (a, b, c)) = , (a, b, c, 1), (a, b, c, 1), (a, b, c, 1)
PP_ITERATE(PP_ITERATE_ITEM_PREPEND, 1, (a, b, c), (a, b, c), (a, b, c)) = , (1, a, b, c), (1, a, b, c), (1, a, b, c)
PP_ITERATE(PP_ITERATE_ITEM_MACRO, MACRO, 1, 2, 3) = MACRO(1)MACRO(2)MACRO(3)
PP_ITERATE(PP_ITERATE_ITEM_SEP, SEP, 1, 2, 3) = SEP 1 SEP 2 SEP 3
PP_ITERATE(PP_ITERATE_ITEM_COMMA, MACRO, 1, 2, 3) = , MACRO(1) , MACRO(2) , MACRO(3)
PP_ITERATE(PP_ITERATE_ITEM_FOLDR, MACRO, 1, 2, 3) = MACRO(1 MACRO(2 MACRO(3
PP_ITERATE(PP_ITERATE_ITEM_FOLDL, _, 1, 2, 3) = , 1) , 2) , 3)

PP_STRIP_COMMAS(1, 2, 3) = 123

PP_STRIP_COMMAS_M(MACRO, 1, 2, 3) = MACRO(1)MACRO(2)MACRO(3)

PP_SEPARATE_LIST(SEP, 1, 2, 3) = 1 SEP 2 SEP 3

PP_SEPARATE_LIST_M(MACRO, SEP, 1, 2, 3) = MACRO(1) SEP MACRO(2) SEP MACRO(3)

PP_APPEND_ALL(4, (1, 2, 3), (1, 2, 3), (1, 2, 3)) = ((1, 2, 3, 4), (1, 2, 3, 4), (1, 2, 3, 4))

PP_PREPEND_ALL(4, (1, 2, 3), (1, 2, 3), (1, 2, 3)) = ((4, 1, 2, 3), (4, 1, 2, 3), (4, 1, 2, 3))

PP_MAP(MACRO, 1, 2, 3) = MACRO(1), MACRO(2), MACRO(3)

PP_MAP_SEP(MACRO, SEP, 1, 2, 3) = MACRO(1) SEP MACRO(2) SEP MACRO(3)

PP_REPEAT(1, 5) = 1, 1, 1, 1, 1
PP_REPEAT(MACRO, 1, 5) = MACRO(1), MACRO(1), MACRO(1), MACRO(1), MACRO(1)
PP_REPEAT(MACRO, 1, 5, SEP) = MACRO(1) SEP MACRO(1) SEP MACRO(1) SEP MACRO(1) SEP MACRO(1)

PP_FOLDL(MACRO, 123, a, b, c) = MACRO( MACRO( MACRO( 123, a), b), c)
PP_FOLDR(MACRO, 123, a, b, c) = MACRO( a, MACRO( b, MACRO( c, 123 ) ) )

PP_COMPOSE((1, 2, 3), MACRO1, MACRO2, MCARO3) = MACRO1(MACRO2(MACRO3(1, 2, 3)))

PP_COMPOSE_MAP(1, MACRO1) = MACRO1(1)
PP_COMPOSE_MAP((1, 2, 3), MACRO1) = MACRO1(1), MACRO1(2), MACRO1(3)
PP_COMPOSE_MAP(1, MACRO1, MACRO2, MCARO3) = MACRO1(MACRO2(MACRO3(1)))
PP_COMPOSE_MAP((1, 2, 3), MACRO1, MACRO2, MCARO3) = MACRO1(MACRO2(MACRO3(1))), MACRO1(MACRO2(MACRO3(2))), MACRO1(MACRO2(MACRO3(3)))

PP_REVERSE(1, 2, 3) = 3, 2, 1

PP_TAILS(1, 2, 3) = (1, 2, 3), (2, 3), (3)

PP_LISTS_TAILS((1, 2, 3), (1, 2, 3), (1, 2, 3)) = (2, 3), (2, 3), (2, 3)

PP_LISTS_HEADS((1, 2, 3), (1, 2, 3), (1, 2, 3)) = (1, 1, 1)

PP_APPLY( PP_LISTS_TAILS ( ((1, 2, 3), (1, 2, 3)) , (d, f) ) ) = ( (1, 2, 3) ) , ( f )
PP_APPLY( PP_LISTS_HEADS ( ( (1, 2, 3) ) , ( f ) ) ) = ( (1, 2, 3), f )

PP_ZIP((1, 2, 3), (a, b, c)) = (1, a), (2, b), (3, c)

PP_ZIP((1, 2, 3, 4), (a, b, c, d)) = (1, a), (2, b), (3, c), (4, d)

PP_ZIP((1, 2, 3, 4, 5), (a, b, c, d, e)) = (1, a), (2, b), (3, c), (4, d), (5, e)

PP_ZIP( ((1), (2), (3)) , ( a, b, c ) ) = ((1), a), ((2), b), ((3), c)

PP_ZIP( ((1, 2, 3), (1, 2, 3), (1, 2, 3), (1, 2, 3), (1, 2, 3)) , ( a, b, c, d, f ) ) = ( (1, 2, 3) , a ) , ( (1, 2, 3) , b ) , ( (1, 2, 3) , c ) , ( (1, 2, 3) , d ) , ( (1, 2, 3) , f )

PP_ZIP( (1, a), (2, b), (3, c) ) = (1, 2, 3), (a, b, c)

PP_MASS_APPEND(((1, 2, 3), (1, 2, 3), (1, 2, 3)), 4, 4, 4) = (1, 2, 3, 4), (1, 2, 3, 4), (1, 2, 3, 4)

PP_MASS_PREPEND(((1, 2, 3), (1, 2, 3), (1, 2, 3)), 4, 4, 4) = (4, 1, 2, 3), (4, 1, 2, 3), (4, 1, 2, 3)
