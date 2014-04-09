/*
 Copyright (c) 2014 Glen Joseph Fernandes
 glenfe at live dot com

 Distributed under the Boost Software License,
 Version 1.0. (See accompanying file LICENSE_1_0.txt
 or copy at http://boost.org/LICENSE_1_0.txt)
*/
#ifndef MAKE_ALIGNED_HPP
#define MAKE_ALIGNED_HPP

#include "aligned_ptr.hpp"

template<class T, class... Args>
inline aligned_ptr<T>
    make_aligned(Args&&... args)
{
    auto p = boost::aligned_alloc(alignof(T),
        sizeof(T));
    if (!p) {
        throw std::bad_alloc();
    }
    try {
        auto q = ::new(p)
            T(std::forward<Args>(args)...);
        return aligned_ptr<T>(q);
    } catch (...) {
        boost::aligned_free(p);
        throw;
    }
}

#endif
