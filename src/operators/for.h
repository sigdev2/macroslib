//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_MACROS_LIB_FOR_H__
#define _HAS_MACROS_LIB_FOR_H__

#include "../config.h"

#include "../common/versions.h"
#include "../preprocessor/utils.h"
#include "../preprocessor/variadic.h"

// fori
#define fori_4(start, len, type, name) for (const PP_SINGLE_TYPE( type ) & _s = ( start ),\
                                           const PP_SINGLE_TYPE( type ) & _l = ( len ),\
                                           PP_SINGLE_TYPE( type ) name = (_s < _l ? _s : _l),\
										   const PP_SINGLE_TYPE( type ) & _e = (_s > _l ? _s : _l);\
										   name < _e; ++ name )
#define fori_3(len, type, name) for ( PP_SINGLE_TYPE( type ) name = 0, const PP_SINGLE_TYPE( type ) & _l = len ; name < _l; ++ name )
#ifdef CXX11
#    define fori_2(len, name) fori_3(len, auto, name)
#else
#    define fori_2(len, name) fori_3(len, TSize, name)
#endif // C++11
#define fori_1(len) fori_2(len, i)
#define fori_0
#define fori(...) PP_VA_FUNC(fori, __VA_ARGS__)

//rfori
#define rfori_4(start, len, type, name) for (const PP_SINGLE_TYPE( type ) & _s = ( start ),\
                                            const PP_SINGLE_TYPE( type ) & _l = ( len ),\
											PP_SINGLE_TYPE( type ) name = (_s > _l ? _s : _l),\
											const PP_SINGLE_TYPE( type ) & _e = (_s < _l ? _s : _l);\
											name > _e; -- name )
#define rfori_3(len, type, name) for ( PP_SINGLE_TYPE( type ) name = ( len ) - 1; name > 0; -- name )
#ifdef CXX11
#    define rfori_2(len, name) rfori_3(len, auto, name)
#else
#    define rfori_2(len, name) rfori_3(len, TSize, name)
#endif // C++11
#define rfori_1(len) rfori_2(len, i)
#define rfori_0
#define rfori(...) PP_VA_FUNC(rfori, __VA_ARGS__)

#define forj(len) fori(len, j)
#define rforj(len) rfori(len, j)

// forij
#define forij_0
#define forij_1(len)
#define forij_2(len1, len2) fori(len1) fori(len2, j)
#define forij_3(len1, len2, name) fori(len1, name) fori(len2, j)
#define forij_4(len1, len2, name1, name2) fori(len1, name1) fori(len2, name2)
#define forij_5(len1, len2, type, name1, name2) fori(len1, name1, type) fori(len2, name2)
#define forij_6(len1, len2, type1, name1, type2, name2) fori(len1, name1, type1) fori(len2, name2, type2)
#define forij(...) PP_VA_FUNC(forij, __VA_ARGS__)

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_MACROS_LIB_FOR_H__