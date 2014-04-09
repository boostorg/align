/*
 Copyright (c) 2014 Glen Joseph Fernandes
 glenfe at live dot com

 Distributed under the Boost Software License,
 Version 1.0. (See accompanying file LICENSE_1_0.txt
 or copy at http://boost.org/LICENSE_1_0.txt)
*/
#ifndef BOOST_ALIGN_DETAIL_ALIGNED_ALLOC_HPP
#define BOOST_ALIGN_DETAIL_ALIGNED_ALLOC_HPP

#include <boost/assert.hpp>
#include <boost/align/align.hpp>
#include <boost/align/detail/alignment_of.hpp>
#include <boost/align/detail/is_alignment.hpp>
#include <cstdlib>

namespace boost {
    namespace alignment {
        namespace detail {
            inline void* aligned_alloc(std::size_t alignment,
                std::size_t size)
            {
                BOOST_ASSERT(is_alignment(alignment));
                enum {
                    VoidAlign = alignment_of<void*>::value
                };
                if (alignment < VoidAlign) {
                    alignment = VoidAlign;
                }
                std::size_t n1 = size + alignment;
                void* p1 = 0;
                void* p2 = std::malloc(n1 + sizeof p2);
                if (p2) {
                    p1 = static_cast<char*>(p2) + sizeof p2;
                    align(alignment, size, p1, n1);
                    *(static_cast<void**>(p1) - 1) = p2;
                }
                return p1;
            }

            inline void aligned_free(void* ptr)
            {
                if (ptr) {
                    void* p1 = *(static_cast<void**>(ptr) - 1);
                    std::free(p1);
                }
            }
        }
    }
}

#endif
