//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_MACROS_LIB_FOREACH_H__
#define __HAS_MACROS_LIB_FOREACH_H__

#include "../config.h"

#include "../common/versions.h"
#include "../preprocessor/utils.h"
#include "../preprocessor/variadic.h"

#ifdef CXX11
#   define forrange(name, begin, end, ...) for ( auto name = ( begin ); name != ( end ); ++( name ))
#   define rforrange(name, begin, end, ...) for ( auto name = ( end ); ( name )-- != ( begin ); )
#else
#   define forrange(name, begin, end, ...) for ( PP_SINGLE_TYPE(__VA_ARGS__) name = ( begin );  name != ( end ); ++( name ))
#   define rforrange(name, begin, end, ...) for ( PP_SINGLE_TYPE(__VA_ARGS__) name = ( end ); ( name )-- != ( begin ); )
#endif // C++11

#ifdef __cplusplus

namespace __MacrosLibPrivate
{
	template<typename IT>
	class MultiIterator : public IT
	{
	public:
	    MacrosIt(const IT& _begin, const IT& end, bool reverse = false)
		    : IT(reverse ? _end : _begin), begin(_begin), end(_end) {}
	    typedef IT TIt;
		IT begin;
		IT end;
	};

	template<typename T>
	MultiIterator<typename T::iterator> _make(const T& collection, bool reverse = false)
	    { return MultiIterator<T::iterator>(STD_BEGIN_IT(collection),
		                                STD_END_IT(collection),
										reverse); }
	template<typename T>
	MultiIterator<typename T::const_iterator> _make(const T& collection, bool reverse = false)
	    { return MultiIterator<T::const_iterator>(STD_CBEGIN_IT(collection),
		                                    STD_CEND_IT(collection),
											reverse); }
	template<typename T>
	MultiIterator<typename T::reverse_iterator> _make(const T& collection, bool reverse = false)
	    { return MultiIterator<T::reverse_iterator>(STD_RBEGIN_IT(collection),
		                                    STD_REND_IT(collection),
											reverse); }
	template<typename T>
	MultiIterator<typename T::const_reverse_iterator> _make(const T& collection, bool reverse = false)
	    { return MultiIterator<T::const_reverse_iterator>(STD_CRBEGIN_IT(collection),
		                                    STD_CREND_IT(collection),
											reverse); }
}

// forit
#ifdef CXX11
#    define forit_3(collection, type, name) for (auto name  = __MacrosLibPrivate::_make( collection ); name != ( name ).end; ++ name )
#    define forit_2(collection, name) forit_3(collection, NULL, name)
#    define forit_1(collection) forit_2(collection, it)
#else
#    define forit_3(collection, type, name) for (__MacrosLibPrivate::MultiIterator<PP_SINGLE_TYPE( type )> name = __MacrosLibPrivate::_make( collection ); name != ( name ).end; ++ name )
#    define forit_2(collection, type) forit_3(collection, ( type ), it)
#    define forit_1(collection)
#endif // C++11
#define forit_0
#define forit(...) PP_VA_FUNC(forit, __VA_ARGS__)

// rfroit
#ifdef CXX11
#    define rforit_3(collection, type, name) for (auto name  = __MacrosLibPrivate::_make( collection ); ( name )-- != ( name ).begin; )
#    define rforit_2(collection, name) rforit_3(collection, NULL, name)
#    define rforit_1(collection) rforit_2(collection, it)
#else
#    define rforit_3(collection, type, name) for (__MacrosLibPrivate::MultiIterator<PP_SINGLE_TYPE( type )> name = __MacrosLibPrivate::_make( collection , true); ( name )-- != ( name ).begin; )
#    define rforit_2(collection, type) rforit_3(collection, ( type ), it)
#    define rforit_1(collection)
#endif // C++11
#define rforit_0
#define rforit(...) PP_VA_FUNC(rforit, __VA_ARGS__)

// note: foreach - is iterate by value. if you want iterate by value - use C++11 range based for or boost foreach,
// else use forit and iterators - it's more useful
#define forch_0
#define forch_1
#ifdef CXX11
#    define forch_2(collection, name) for(auto& name : collection )
#    define forch_3(collection, name, ...) forch_2(collection, name)
#else
#    define forch_2(collection, name)
#    define forch3(collection, name, ...) PP_SINGLE_TYPE(__VA_ARGS__)::value_type name = STD_PAIR_VALUE(collection.begin()); \
                                        for (__MacrosLibPrivate::MultiIterator<PP_SINGLE_TYPE(__VA_ARGS__)> name##_it = __MacrosLibPrivate::_make( collection ); \
										     name##_it != ( name##_it ).end; ++ name##_it , name = * name##_it )
#endif // CXX11
#define forch(...) PP_VA_FUNC(forch, __VA_ARGS__)

#define forech(...) forch(__VA_ARGS__)
#define foreh(...) forch(__VA_ARGS__)
#ifndef foreach
#    define foreach(...) forch(__VA_ARGS__)
#endif // foreach

#ifdef CXX11
#define forval(colleltion) foreach(colleltio, val)
#else
#define forval(colleltion, ...) foreach(colleltio, val, (__VA_ARGS__))
#endif // CXX11

#endif // __cplusplus

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_MACROS_LIB_FOREACH_H__