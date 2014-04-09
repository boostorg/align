/*
 Copyright (c) 2014 Glen Joseph Fernandes
 glenfe at live dot com

 Distributed under the Boost Software License,
 Version 1.0. (See accompanying file LICENSE_1_0.txt
 or copy at http://boost.org/LICENSE_1_0.txt)
*/
#ifndef BOOST_ALIGN_DETAIL_ALIGNMENT_OF_HPP
#define BOOST_ALIGN_DETAIL_ALIGNMENT_OF_HPP

#include <boost/config.hpp>

#if !defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <type_traits>
#else
#include <boost/type_traits/alignment_of.hpp>
#endif

namespace boost {
    namespace alignment {
        namespace detail {
#if !defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
            using std::alignment_of;
#else
            using boost::alignment_of;
#endif
        }
    }
}

#endif
