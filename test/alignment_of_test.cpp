/*
 Copyright (c) 2014 Glen Joseph Fernandes
 glenfe at live dot com

 Distributed under the Boost Software License,
 Version 1.0. (See accompanying file LICENSE_1_0.txt
 or copy at http://boost.org/LICENSE_1_0.txt)
*/
#include <boost/align/alignment_of.hpp>
#include <boost/core/lightweight_test.hpp>
#include <cstddef>

// remove_reference

template<class T> struct remove_reference
{
    typedef T type;
};

template<class T> struct remove_reference< T& >: remove_reference< T > {};
#if !defined( BOOST_NO_CXX11_RVALUE_REFERENCES )
template<class T> struct remove_reference< T&& >: remove_reference< T > {};
#endif

// remove_extents

template<class T> struct remove_extents
{
    typedef T type;
};

template<class T> struct remove_extents< T[] >: remove_extents< T > {};
template<class T, std::size_t N> struct remove_extents< T[N] >: remove_extents< T > {};

// remove_cv

template<class T> struct remove_cv
{
    typedef T type;
};

template<class T> struct remove_cv< T const >: remove_cv< T > {};
template<class T> struct remove_cv< T volatile >: remove_cv< T > {};
template<class T> struct remove_cv< T const volatile >: remove_cv< T > {};

// remove_cv_array_ref

template<class T> struct remove_cv_array_ref
{
    typedef typename remove_reference<T>::type noref;
    typedef typename remove_extents<noref>::type noarray;
    typedef typename remove_cv<noarray>::type type;
};

template<class T>
struct padded {
    char unit;
    typename remove_cv_array_ref< T >::type object;
};

template<class T>
void test_impl()
{
    BOOST_TEST(boost::alignment::
        alignment_of<T>::value == offsetof(padded<T>, object));
}

template<class T>
void test_reference()
{
    test_impl<T>();
    test_impl<T&>();
#if !defined( BOOST_NO_CXX11_RVALUE_REFERENCES )
    test_impl<T&&>();
#endif
}

template<class T>
void test_array()
{
    test_reference<T>();
    test_impl<T[]>(); // T (&) [] is illegal
    test_reference<T[2]>();
}

template<class T>
void test_cv()
{
    test_array<T>();
    test_array<T const>();
    test_array<T volatile>();
    test_array<T const volatile>();
}

template<class T> struct W1
{
    T t;
};

template<class T> class W2
{
    T t;
};

template<class T> union W3
{
    T t;
};

template<class T>
void test()
{
    test_cv<T>();
    test_cv< W1<T> >();
    test_cv< W2<T> >();
    test_cv< W3<T> >();
}

class X;

enum E
{
    v = 1
};

struct S
{
};

class C
{
};

union U
{
};

int main()
{
    // integral
    test<bool>();

    test<char>();
    test<signed char>();
    test<unsigned char>();
    test<wchar_t>();
#if !defined( BOOST_NO_CXX11_CHAR16_T  )
    test<char16_t>();
#endif
#if !defined( BOOST_NO_CXX11_CHAR32_T  )
    test<char32_t>();
#endif

    test<short>();
    test<unsigned short>();
    test<int>();
    test<unsigned int>();
    test<long>();
    test<unsigned long>();
#if !defined( BOOST_NO_LONG_LONG )
    test<long long>();
    test<unsigned long long>();
#endif

    // floating point
    test<float>();
    test<double>();
    test<long double>();

    // nullptr_t
#if !defined( BOOST_NO_CXX11_NULLPTR ) && !defined( BOOST_NO_CXX11_DECLTYPE )
    test<decltype(nullptr)>();
#endif

    // pointer
    test<void*>();
    test<char*>();
    test<int*>();
    test<X*>();
    test<void(*)()>();

    // member pointer
    test<int X::*>();
    test<int (X::*)()>();

    // enum
    test<E>();

    // class
    test<S>();
    test<C>();
    test<U>();

    return boost::report_errors();
}
