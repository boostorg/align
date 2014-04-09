/*
 Copyright (c) 2014 Glen Joseph Fernandes
 glenfe at live dot com

 Distributed under the Boost Software License,
 Version 1.0. (See accompanying file LICENSE_1_0.txt
 or copy at http://boost.org/LICENSE_1_0.txt)
*/
#include "aligned_vector.hpp"

enum {
    cache_line = 64
};

int main()
{
    aligned_vector<int, cache_line> v(32);
    v[0] = 1;
}
