/*
 Copyright (c) 2014 Glen Joseph Fernandes
 glenfe at live dot com

 Distributed under the Boost Software License,
 Version 1.0. (See accompanying file LICENSE_1_0.txt
 or copy at http://boost.org/LICENSE_1_0.txt)
*/
#ifndef BOOST_ALIGN_DETAIL_ALIGNED_ALLOC_SUNOS_HPP
#define BOOST_ALIGN_DETAIL_ALIGNED_ALLOC_SUNOS_HPP

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
                return memalign(alignment, size);
            }

            inline void aligned_free(void* ptr)
            {
                free(ptr);
            }
        }
    }
}

#endif
