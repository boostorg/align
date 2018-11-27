/*
Copyright 2018 Glen Joseph Fernandes
(glenjofe@gmail.com)

Distributed under the Boost Software License, Version 1.0.
(http://www.boost.org/LICENSE_1_0.txt)
*/
#include <boost/align/aligned_allocator.hpp>

struct S;

void value_test()
{
    boost::alignment::aligned_allocator<S> a;
    (void)a;
}

void rebind_test()
{
    boost::alignment::aligned_allocator<int>::rebind<S>::other a;
    (void)a;
}
