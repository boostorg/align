/*
 Copyright (c) 2014 Glen Joseph Fernandes
 glenfe at live dot com

 Distributed under the Boost Software License,
 Version 1.0. (See accompanying file LICENSE_1_0.txt
 or copy at http://boost.org/LICENSE_1_0.txt)
*/
#ifndef BOOST_ALIGN_HPP
#define BOOST_ALIGN_HPP

/**
 Boost.Align
 in Boost namespace.

 @file
 @author Glen Fernandes
*/

#include <boost/align/align.hpp>
#include <boost/align/aligned_alloc.hpp>
#include <boost/align/aligned_allocator.hpp>
#include <boost/align/aligned_allocator_adaptor.hpp>
#include <boost/align/aligned_delete.hpp>
#include <boost/align/is_aligned.hpp>

/**
 Boost namespace.
*/
namespace boost {
    /**
     @cond
    */
    using alignment::align;
    using alignment::aligned_alloc;
    using alignment::aligned_free;
    using alignment::aligned_allocator;
    using alignment::aligned_allocator_adaptor;
    using alignment::aligned_delete;
    using alignment::is_aligned;
    /**
     @endcond
    */
}

/**
 @file
 @code{.cpp}

 namespace boost {
   using alignment::align;
   using alignment::aligned_alloc;
   using alignment::aligned_free;
   using alignment::aligned_allocator;
   using alignment::aligned_allocator_adaptor;
   using alignment::aligned_delete;
   using alignment::is_aligned;
 }

 @endcode
*/

#endif
