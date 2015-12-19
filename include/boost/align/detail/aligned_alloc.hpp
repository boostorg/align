/*
(c) 2014-2015 Glen Joseph Fernandes
<glenjofe -at- gmail.com>

Distributed under the Boost Software
License, Version 1.0.
http://boost.org/LICENSE_1_0.txt
*/
#ifndef BOOST_ALIGN_DETAIL_ALIGNED_ALLOC_HPP
#define BOOST_ALIGN_DETAIL_ALIGNED_ALLOC_HPP

#include <boost/align/detail/allocation.hpp>
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
        minimum = alignment_of<void*>::value
    };
    if (alignment < minimum) {
        alignment = minimum;
    }
    std::size_t n = size + alignment - minimum;
    void* p1 = detail::allocate(sizeof(void*) + n);
    if (!p1) {
        return 0;
    }
    void* p2 = static_cast<char*>(p1) + sizeof p1;
    (void)align(alignment, size, p2, n);
    *(static_cast<void**>(p2) - 1) = p1;
    return p2;
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
