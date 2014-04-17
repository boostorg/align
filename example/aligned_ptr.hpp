/*
 Copyright (c) 2014 Glen Joseph Fernandes
 glenfe at live dot com

 Distributed under the Boost Software License,
 Version 1.0. (See accompanying file LICENSE_1_0.txt
 or copy at http://boost.org/LICENSE_1_0.txt)
*/
#ifndef ALIGNED_PTR_HPP
#define ALIGNED_PTR_HPP

#include <boost/align.hpp>
#include <memory>

template<class T>
using aligned_ptr = std::unique_ptr<T,
    boost::aligned_delete>;

#endif
