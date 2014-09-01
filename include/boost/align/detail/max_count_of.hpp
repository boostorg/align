/*
 (c) 2014 Glen Joseph Fernandes
 glenjofe at gmail dot com

 Distributed under the Boost Software
 License, Version 1.0.
 http://boost.org/LICENSE_1_0.txt
*/
#ifndef BOOST_ALIGN_DETAIL_MAX_COUNT_OF_HPP
#define BOOST_ALIGN_DETAIL_MAX_COUNT_OF_HPP

#include <cstddef>

namespace boost {
    namespace alignment {
        namespace detail {
            template<class T>
            struct max_count_of {
                enum {
                    value = ~static_cast<std::size_t>(0) / sizeof(T)
                };
            };
        }
    }
}

#endif
