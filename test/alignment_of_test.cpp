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

template<class T>
struct padded {
    char unit;
    T object;
};

template<class T>
void test()
{
    BOOST_TEST(boost::alignment::
        alignment_of<T>::value == offsetof(padded<T>, object));
}

int main()
{
    test<bool>();
    test<char>();
    test<short>();
    test<int>();
    test<long>();
    test<float>();
    test<double>();
    test<long double>();
    test<int[4]>();
    test<void*>();
    test<void(*)()>();

    return boost::report_errors();
}
