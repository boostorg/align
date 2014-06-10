/*
 Copyright (c) 2014 Glen Joseph Fernandes
 glenfe at live dot com

 Distributed under the Boost Software License,
 Version 1.0. (See accompanying file LICENSE_1_0.txt
 or copy at http://boost.org/LICENSE_1_0.txt)
*/
#ifndef BOOST_ALIGN_DETAIL_ALIGN_TYPE_HPP
#define BOOST_ALIGN_DETAIL_ALIGN_TYPE_HPP

#include <boost/config.hpp>
#include <cstddef>

namespace boost {
    namespace alignment {
        namespace detail {
            template<class T>
            struct no_ref {
                typedef T type;
            };

            template<class T>
            struct no_ref<T&> {
                typedef T type;
            };

#if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
            template<class T>
            struct no_ref<T&&> {
                typedef T type;
            };
#endif

            template<class T>
            struct no_extents {
                typedef T type;
            };

            template<class T>
            struct no_extents<T[]> {
                typedef typename no_extents<T>::type type;
            };

            template<class T, std::size_t N>
            struct no_extents<T[N]> {
                typedef typename no_extents<T>::type type;
            };

            template<class T>
            struct no_const {
                typedef T type;
            };

            template<class T>
            struct no_const<const T> {
                typedef T type;
            };

            template<class T>
            struct no_volatile {
                typedef T type;
            };

            template<class T>
            struct no_volatile<volatile T> {
                typedef T type;
            };

            template<class T>
            struct no_cv {
                typedef typename no_volatile<typename
                    no_const<T>::type>::type type;
            };

            template<class T>
            struct align_type {
                typedef typename no_cv<typename no_extents<typename
                    no_ref<T>::type>::type>::type type;
            };
        }
    }
}

#endif
