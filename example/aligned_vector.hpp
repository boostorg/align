/*
 Copyright (c) 2014 Glen Joseph Fernandes
 glenfe at live dot com

 Distributed under the Boost Software License,
 Version 1.0. (See accompanying file LICENSE_1_0.txt
 or copy at http://boost.org/LICENSE_1_0.txt)
*/
#ifndef ALIGNED_VECTOR_HPP
#define ALIGNED_VECTOR_HPP

#include <boost/align.hpp>
#include <vector>

template<class T, std::size_t Alignment = 1>
using aligned_vector = std::vector<T,
    boost::aligned_allocator<T, Alignment> >;

#endif
