/*
 Copyright (c) 2014 Glen Joseph Fernandes
 glenfe at live dot com

 Distributed under the Boost Software License,
 Version 1.0. (See accompanying file LICENSE_1_0.txt
 or copy at http://boost.org/LICENSE_1_0.txt)
*/
#ifndef BOOST_ALIGN_DETAIL_ALIGN_HPP
#define BOOST_ALIGN_DETAIL_ALIGN_HPP

#include <boost/assert.hpp>
#include <boost/align/detail/address.hpp>
#include <boost/align/detail/is_alignment.hpp>

namespace boost {
    namespace alignment {
        namespace detail {
            inline void* align(std::size_t alignment, std::size_t size,
                void*& ptr, std::size_t& space)
            {
                BOOST_ASSERT(is_alignment(alignment));
                std::size_t n1 = address_t(ptr) & (alignment - 1);
                if (n1 != 0) {
                    n1 = alignment - n1;
                }
                void* p1 = 0;
                if (n1 <= space && size <= space - n1) {
                    p1 = static_cast<char*>(ptr) + n1;
                    ptr = p1;
                    space -= n1;
                }
                return p1;
            }
        }
    }
}

#endif
