/*
 (c) 2015 NumScale SAS
 (c) 2015 LRI UMR 8623 CNRS/University Paris Sud XI

 Distributed under the Boost Software
 License, Version 1.0.
 http://boost.org/LICENSE_1_0.txt
*/
#ifndef BOOST_ALIGN_ASSUME_ALIGNED_HPP_INCLUDED
#define BOOST_ALIGN_ASSUME_ALIGNED_HPP_INCLUDED

#include <boost/config.hpp>
#include <cstddef>

#if defined(BOOST_MSVC)

#define BOOST_ALIGN_ASSUME_ALIGNED(PTR,ALIGN) __assume((std::size_t)(PTR) % (ALIGN) == 0)

#elif defined(__INTEL_COMPILER)

#define BOOST_ALIGN_ASSUME_ALIGNED(PTR,ALIGN)  __assume_aligned((PTR), (ALIGN))

#elif defined(BOOST_GCC_VERSION) && (BOOST_GCC_VERSION >= 40700)

#define BOOST_ALIGN_ASSUME_ALIGNED(PTR,ALIGN) (PTR) = __builtin_assume_aligned((PTR), (ALIGN))

#else

#define BOOST_ALIGN_ASSUME_ALIGNED(PTR,ALIGN)

#endif

#endif
