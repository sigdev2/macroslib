//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_MACROS_LIB_INTERFACES_H__
#define __HAS_MACROS_LIB_INTERFACES_H__

#include "debug.h"

#ifdef __cplusplus

// Iterator

#define ITERATOR_INTERFACE(...)  typename __VA_ARGS__::iterator_category, \
	typename __VA_ARGS__::value_type, \
	typename __VA_ARGS__::difference_type, \
	typename __VA_ARGS__::pointer, \
	typename __VA_ARGS__::reference
	
#define ITERATOR_INTERFACE_MIRROR(...)\
	typedef typename __VA_ARGS__::iterator_category iterator_category; \
	typedef typename __VA_ARGS__::value_type value_type; \
	typedef typename __VA_ARGS__::difference_type difference_type; \
	typedef typename __VA_ARGS__::pointer pointer; \
	typedef typename __VA_ARGS__::reference reference;

#define IS_ITERATOR_TYPE(...)  TYPE_ASSERT(ITERATOR_INTERFACE(__VA_ARGS__))

// Pair

#define PAIR_INTERFACE(...)  typename __VA_ARGS__::first_type, \
	typename __VA_ARGS__::second_type
	
#define PAIR_INTERFACE_MIRROR(...)  typedef typename __VA_ARGS__::first_type first_type; \
	typedef typename __VA_ARGS__::second_type second_type;
	
#define IS_PAIR_INTERFACE(...)  TYPE_ASSERT(PAIR_INTERFACE(__VA_ARGS__))

// Key-value

#define KEYVALUE_INTERFACE(...)  typename __VA_ARGS__::key_type, \
	typename __VA_ARGS__::value_type
	
#define KEYVALUE_INTERFACE_MIRROR(...)  typedef typename __VA_ARGS__::key_type key_type; \
	typedef typename __VA_ARGS__::value_type value_type;
	
#define IS_KEYVALUE_INTERFACE(...)  TYPE_ASSERT(KEYVALUE_INTERFACE(__VA_ARGS__))

#endif // __cplusplus

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_MACROS_LIB_INTERFACES_H__