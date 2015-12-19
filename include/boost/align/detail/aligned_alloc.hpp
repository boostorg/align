/*
(c) 2014-2015 Glen Joseph Fernandes
<glenjofe -at- gmail.com>

Distributed under the Boost Software
License, Version 1.0.
http://boost.org/LICENSE_1_0.txt
*/
#ifndef BOOST_ALIGN_DETAIL_ALIGNED_ALLOC_HPP
#define BOOST_ALIGN_DETAIL_ALIGNED_ALLOC_HPP

#include <boost/align/detail/allocate.hpp>
#include <boost/align/detail/is_alignment.hpp>
#include <boost/align/align.hpp>
#include <boost/align/alignment_of.hpp>
#include <boost/assert.hpp>
#include <boost/config.hpp>

namespace boost {
namespace alignment {

inline void* aligned_alloc(std::size_t alignment, std::size_t size)
    BOOST_NOEXCEPT
{
    BOOST_ASSERT(detail::is_alignment(alignment));
    enum {
        min_align = alignment_of<void*>::value
    };
    if (alignment < min_align) {
        alignment = min_align;
    }
    std::size_t n = size + alignment - min_align;
    void* p1 = 0;
    void* p2 = detail::allocate(sizeof(void*) + n);
    if (p2) {
        p1 = static_cast<char*>(p2) + sizeof p2;
        (void)align(alignment, size, p1, n);
        *(static_cast<void**>(p1) - 1) = p2;
    }
    return p1;
}

inline void aligned_free(void* ptr) BOOST_NOEXCEPT
{
    if (ptr) {
        detail::deallocate(*(static_cast<void**>(ptr) - 1));
    }
}

} /* .alignment */
} /* .boost */

#endif
