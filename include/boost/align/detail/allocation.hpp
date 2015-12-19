/*
(c) 2015 Glen Joseph Fernandes
<glenjofe -at- gmail.com>

Distributed under the Boost Software
License, Version 1.0.
http://boost.org/LICENSE_1_0.txt
*/
#ifndef BOOST_ALIGN_DETAIL_ALLOCATION_HPP
#define BOOST_ALIGN_DETAIL_ALLOCATION_HPP

#include <boost/config.hpp>
#include <cstdlib>

namespace boost {
namespace alignment {
namespace detail {

inline void* allocate(std::size_t size) BOOST_NOEXCEPT
{
    return std::malloc(size);
}

inline void deallocate(void* ptr) BOOST_NOEXCEPT
{
    std::free(ptr);
}

} /* .detail */
} /* .alignment */
} /* .boost */

#endif
