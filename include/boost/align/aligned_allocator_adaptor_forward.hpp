/*
 Copyright (c) 2014 Glen Joseph Fernandes
 glenfe at live dot com

 Distributed under the Boost Software License,
 Version 1.0. (See accompanying file LICENSE_1_0.txt
 or copy at http://boost.org/LICENSE_1_0.txt)
*/
#ifndef BOOST_ALIGN_ALIGNED_ALLOCATOR_ADAPTOR_FORWARD_HPP
#define BOOST_ALIGN_ALIGNED_ALLOCATOR_ADAPTOR_FORWARD_HPP

/**
 Class template aligned_allocator_adaptor
 forward declaration.

 @file
 @author Glen Fernandes
*/

#include <cstddef>

/**
 Boost namespace.
*/
namespace boost {
    /**
     Alignment namespace.
    */
    namespace alignment {
        /**
         @cond
        */
        template<class Allocator, std::size_t Alignment = 1>
        class aligned_allocator_adaptor;
        /**
         @endcond
        */
    }
}

/**
 @file
 @code{.cpp}

 namespace boost {
   namespace alignment {
     template<class Allocator, std::size_t Alignment = 1>
     class aligned_allocator_adaptor;
   }
 }

 @endcode
*/

#endif
