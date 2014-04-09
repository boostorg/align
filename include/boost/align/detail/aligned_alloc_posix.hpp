/*
 Copyright (c) 2014 Glen Joseph Fernandes
 glenfe at live dot com

 Distributed under the Boost Software License,
 Version 1.0. (See accompanying file LICENSE_1_0.txt
 or copy at http://boost.org/LICENSE_1_0.txt)
*/
#ifndef BOOST_ALIGN_DETAIL_ALIGNED_ALLOC_POSIX_HPP
#define BOOST_ALIGN_DETAIL_ALIGNED_ALLOC_POSIX_HPP

#include <boost/assert.hpp>
#include <boost/align/detail/is_alignment.hpp>
#include <stdlib.h>

namespace boost {
    namespace alignment {
        namespace detail {
            inline void* aligned_alloc(std::size_t alignment,
                std::size_t size)
            {
                BOOST_ASSERT(is_alignment(alignment));
                enum {
                    VoidSize = sizeof(void*)
                };
                if (alignment < VoidSize) {
                    alignment = VoidSize;
                }
                void* p1;
                if (posix_memalign(&p1, alignment, size) != 0) {
                    p1 = 0;
                }
                return p1;
            }

            inline void aligned_free(void* ptr)
            {
                free(ptr);
            }
        }
    }
}

#endif
