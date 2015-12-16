/*
(c) 2015 Glen Joseph Fernandes
<glenjofe -at- gmail.com>

Distributed under the Boost Software
License, Version 1.0.
http://boost.org/LICENSE_1_0.txt
*/
#ifndef BOOST_ALIGN_DETAIL_ALIGN_DOWN_HPP
#define BOOST_ALIGN_DETAIL_ALIGN_DOWN_HPP

#include <boost/align/detail/is_alignment.hpp>
#include <boost/assert.hpp>
#include <boost/config.hpp>
#include <cstddef>

namespace boost {
namespace alignment {

BOOST_CONSTEXPR inline std::size_t align_down(std::size_t alignment,
    std::size_t value) BOOST_NOEXCEPT
{
    return value & ~(alignment - 1);
}

inline void* align_down(std::size_t alignment, void* ptr) BOOST_NOEXCEPT
{
    BOOST_ASSERT(detail::is_alignment(alignment));
    return reinterpret_cast<void*>(align_down(alignment,
        reinterpret_cast<std::size_t>(ptr)));
}

} /* .alignment */
} /* .boost */

#endif
