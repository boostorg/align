/*
(c) 2015 Glen Joseph Fernandes
<glenjofe -at- gmail.com>

Distributed under the Boost Software
License, Version 1.0.
http://boost.org/LICENSE_1_0.txt
*/
#ifndef BOOST_ALIGN_DETAIL_ALLOCATE_HPP
#define BOOST_ALIGN_DETAIL_ALLOCATE_HPP

#if defined(BOOST_ALIGN_USE_ALLOCATE)
#include <cstddef>
#else
#include <cstdlib>
#endif

namespace boost {
namespace alignment {

#if defined(BOOST_ALIGN_USE_ALLOCATE)
void* allocate(std::size_t size);

void deallocate(void* ptr);
#endif

namespace detail {

inline void* allocate(std::size_t size)
{
#if defined(BOOST_ALIGN_USE_ALLOCATE)
    return ::boost::alignment::allocate(size);
#else
    return std::malloc(size);
#endif
}

inline void deallocate(void* ptr)
{
#if defined(BOOST_ALIGN_USE_ALLOCATE)
    ::boost::alignment::deallocate(ptr);
#else
    std::free(ptr);
#endif
}

} /* .detail */
} /* .alignment */
} /* .boost */

#endif
