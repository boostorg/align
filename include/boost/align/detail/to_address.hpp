/*
Copyright 2017 Glen Joseph Fernandes
(glenjofe@gmail.com)

Distributed under the Boost Software License, Version 1.0.
(http://www.boost.org/LICENSE_1_0.txt)
*/
#ifndef BOOST_ALIGN_DETAIL_TO_ADDRESS_HPP
#define BOOST_ALIGN_DETAIL_TO_ADDRESS_HPP

#include <boost/config.hpp>

#if !defined(BOOST_NO_CXX11_ALLOCATOR)
#include <memory>
#endif

namespace boost {
namespace alignment {
namespace detail {

template<class T>
inline T*
to_address(T* v) BOOST_NOEXCEPT
{
    return v;
}

#if !defined(BOOST_NO_CXX11_ALLOCATOR)
template<class T>
inline typename std::pointer_traits<T>::element_type*
to_address(T v) BOOST_NOEXCEPT
{
    return boost::alignment::detail::to_address(v.operator->());
}
#endif

} /* detail */
} /* alignment */
} /* boost */

#endif
