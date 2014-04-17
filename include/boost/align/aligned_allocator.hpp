/*
 Copyright (c) 2014 Glen Joseph Fernandes
 glenfe at live dot com

 Distributed under the Boost Software License,
 Version 1.0. (See accompanying file LICENSE_1_0.txt
 or copy at http://boost.org/LICENSE_1_0.txt)
*/
#ifndef BOOST_ALIGN_ALIGNED_ALLOCATOR_HPP
#define BOOST_ALIGN_ALIGNED_ALLOCATOR_HPP

#include <boost/config.hpp>
#include <boost/static_assert.hpp>
#include <boost/throw_exception.hpp>
#include <boost/align/aligned_alloc.hpp>
#include <boost/align/aligned_allocator_forward.hpp>
#include <boost/align/detail/addressof.hpp>
#include <boost/align/detail/alignment_of.hpp>
#include <boost/align/detail/is_alignment_const.hpp>
#include <boost/align/detail/max_align.hpp>
#include <boost/align/detail/max_count_of.hpp>
#include <new>

#if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
#include <utility>
#endif

namespace boost {
    namespace alignment {
        template<std::size_t Alignment>
        class aligned_allocator<void, Alignment> {
            BOOST_STATIC_ASSERT(detail::
                is_alignment_const<Alignment>::value);

        public:
            typedef void value_type;
            typedef void* pointer;
            typedef const void* const_pointer;

            template<class U>
            struct rebind {
                typedef aligned_allocator<U, Alignment> other;
            };
        };

        template<class T, std::size_t Alignment>
        class aligned_allocator {
            BOOST_STATIC_ASSERT(detail::
                is_alignment_const<Alignment>::value);

        public:
            typedef T value_type;
            typedef T* pointer;
            typedef const T* const_pointer;
            typedef void* void_pointer;
            typedef const void* const_void_pointer;
            typedef std::size_t size_type;
            typedef std::ptrdiff_t difference_type;
            typedef T& reference;
            typedef const T& const_reference;

        private:
            enum {
                TypeAlign = detail::
                    alignment_of<value_type>::value,
                MaxAlign = detail::
                    max_align<Alignment, TypeAlign>::value
            };

        public:
            template<class U>
            struct rebind {
                typedef aligned_allocator<U, Alignment> other;
            };

#if !defined(BOOST_NO_CXX11_DEFAULTED_FUNCTIONS)
            aligned_allocator() BOOST_NOEXCEPT = default;
#else
            aligned_allocator() BOOST_NOEXCEPT {
            }
#endif

            template<class U>
            aligned_allocator(const aligned_allocator<U,
                Alignment>&) BOOST_NOEXCEPT {
            }

            pointer address(reference value) const BOOST_NOEXCEPT {
                return detail::addressof(value);
            }

            const_pointer address(const_reference value) const
                BOOST_NOEXCEPT {
                return detail::addressof(value);
            }

            pointer allocate(size_type size, const_void_pointer = 0) {
                void* p = aligned_alloc(MaxAlign, sizeof(T) * size);
                if (!p && size > 0) {
                    boost::throw_exception(std::bad_alloc());
                }
                return static_cast<T*>(p);
            }

            void deallocate(pointer memory, size_type) {
                alignment::aligned_free(memory);
            }

            BOOST_CONSTEXPR size_type max_size() const
                BOOST_NOEXCEPT {
                return detail::max_count_of<T>::value;
            }

#if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
#if !defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)
            template<class U, class... Args>
            void construct(U* memory, Args&&... args) {
                void* p = memory;
                ::new(p) U(std::forward<Args>(args)...);
            }
#else
            template<class U, class V>
            void construct(U* memory, V&& value) {
                void* p = memory;
                ::new(p) U(std::forward<V>(value));
            }
#endif
#else
            template<class U, class V>
            void construct(U* memory, const V& value) {
                void* p = memory;
                ::new(p) U(value);
            }
#endif

            template<class U>
            void construct(U* memory) {
                void* p = memory;
                ::new(p) U();
            }

            template<class U>
            void destroy(U* memory) {
                (void)memory;
                memory->~U();
            }
        };

        template<class T1, class T2, std::size_t Alignment>
        inline bool operator==(const aligned_allocator<T1,
            Alignment>&, const aligned_allocator<T2,
            Alignment>&) BOOST_NOEXCEPT
        {
            return true;
        }

        template<class T1, class T2, std::size_t Alignment>
        inline bool operator!=(const aligned_allocator<T1,
            Alignment>&, const aligned_allocator<T2,
            Alignment>&) BOOST_NOEXCEPT
        {
            return false;
        }
    }
}

#endif
