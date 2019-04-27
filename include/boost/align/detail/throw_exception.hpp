/*
Copyright 2019 Glen Joseph Fernandes
(glenjofe@gmail.com)

Distributed under the Boost Software License, Version 1.0.
(http://www.boost.org/LICENSE_1_0.txt)
*/
#ifndef BOOST_ALIGN_DETAIL_THROW_EXCEPTION_HPP
#define BOOST_ALIGN_DETAIL_THROW_EXCEPTION_HPP

#include <boost/config.hpp>
#include <exception>

namespace boost {

#if defined(BOOST_NO_EXCEPTIONS)
void throw_exception(const std::exception&);
#endif

namespace alignment {
namespace detail {

#if !defined(BOOST_NO_EXCEPTIONS)
inline void
throw_exception(const std::exception& error)
{
    throw error;
}
#else
inline void
throw_exception(const std::exception& error)
{
    boost::throw_exception(error);
}
#endif

} /* detail */
} /* alignment */
} /* boost */

#endif
