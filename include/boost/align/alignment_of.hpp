/*
 Copyright (c) 2014 Glen Joseph Fernandes
 glenfe at live dot com

 Distributed under the Boost Software License,
 Version 1.0. (See accompanying file LICENSE_1_0.txt
 or copy at http://boost.org/LICENSE_1_0.txt)
*/
#ifndef BOOST_ALIGN_ALIGNMENT_OF_HPP
#define BOOST_ALIGN_ALIGNMENT_OF_HPP

/**
 Class template alignment_of.

 @file
 @author Glen Fernandes
*/

#include <boost/config.hpp>

/**
 @cond
*/
#if !defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/align/detail/alignment_of_cxx11.hpp>
#elif BOOST_MSVC >= 1400
#include <boost/align/detail/alignment_of_msvc.hpp>
#elif defined(BOOST_CLANG)
#include <boost/align/detail/alignment_of_clang.hpp>
#elif (__GNUC__ > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 3))
#include <boost/align/detail/alignment_of_gcc.hpp>
#elif defined(__ghs__) && (__GHS_VERSION_NUMBER >= 600)
#include <boost/align/detail/alignment_of_gcc.hpp>
#elif defined(__CODEGEARC__)
#include <boost/align/detail/alignment_of_codegear.hpp>
#else
#include <boost/align/detail/alignment_of.hpp>
#endif
/**
 @endcond
*/

/**
 Boost namespace.
*/
namespace boost {
    /**
     Alignment namespace.
    */
    namespace alignment {
        /**
         Class template alignment_of.

         @note This trait type has one member, `value`,
           which is the alignment value of the type.

         @remark **Value:** `alignof(T)`.
        */
        template<class T>
        struct alignment_of;
    }
}

#endif
