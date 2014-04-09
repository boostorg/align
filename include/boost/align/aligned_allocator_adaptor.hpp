/*
 Copyright (c) 2014 Glen Joseph Fernandes
 glenfe at live dot com

 Distributed under the Boost Software License,
 Version 1.0. (See accompanying file LICENSE_1_0.txt
 or copy at http://boost.org/LICENSE_1_0.txt)
*/
#ifndef BOOST_ALIGN_ALIGNED_ALLOCATOR_ADAPTOR_HPP
#define BOOST_ALIGN_ALIGNED_ALLOCATOR_ADAPTOR_HPP

#include <boost/static_assert.hpp>
#include <boost/align/align.hpp>
#include <boost/align/detail/addressof.hpp>
#include <boost/align/detail/alignment_of.hpp>
#include <boost/align/detail/is_power_of_2.hpp>
#include <boost/align/detail/max_size.hpp>
#include <new>

#if !defined(BOOST_NO_CXX11_ALLOCATOR)
#include <memory>
#endif

#if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
#include <utility>
#endif

namespace boost {
    namespace alignment {
        template<class Allocator, std::size_t Alignment = 1>
        class aligned_allocator_adaptor
            : public Allocator {
            BOOST_STATIC_ASSERT(detail::
                is_power_of_2<Alignment>::value);

#if !defined(BOOST_NO_CXX11_ALLOCATOR)
            typedef std::allocator_traits<Allocator> Traits;
            typedef typename Traits::
                template rebind_alloc<char> CharAlloc;
            typedef typename Traits::
                template rebind_traits<char> CharTraits;
            typedef typename CharTraits::pointer CharPtr;
#else
            typedef typename Allocator::
                template rebind<char>::other CharAlloc;
            typedef typename CharAlloc::pointer CharPtr;
#endif

        public:
            typedef Allocator allocator_type;

#if !defined(BOOST_NO_CXX11_ALLOCATOR)
            typedef typename Traits::value_type value_type;
            typedef typename Traits::size_type size_type;
#else
            typedef typename Allocator::value_type value_type;
            typedef typename Allocator::size_type size_type;
#endif

            typedef value_type* pointer;
            typedef const value_type* const_pointer;
            typedef void* void_pointer;
            typedef const void* const_void_pointer;
            typedef std::ptrdiff_t difference_type;

        private:
            enum {
                TypeAlign = detail::
                    alignment_of<value_type>::value,
                PtrAlign = detail::
                    alignment_of<CharPtr>::value,
                BlockAlign = detail::
                    max_size<PtrAlign, TypeAlign>::value,
                MaxAlign = detail::
                    max_size<Alignment, BlockAlign>::value
            };

        public:
            template<class U>
            struct rebind {
#if !defined(BOOST_NO_CXX11_ALLOCATOR)
                typedef aligned_allocator_adaptor<typename Traits::
                    template rebind_alloc<U>, Alignment> other;
#else
                typedef aligned_allocator_adaptor<typename Allocator::
                    template rebind<U>::other, Alignment> other;
#endif
            };

            aligned_allocator_adaptor()
                : Allocator() {
            }

#if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
            template<class A>
            explicit aligned_allocator_adaptor(A&& alloc)
                : Allocator(std::forward<A>(alloc)) {
            }
#else
            template<class A>
            explicit aligned_allocator_adaptor(const A& alloc)
                : Allocator(alloc) {
            }
#endif

            template<class U>
            aligned_allocator_adaptor(const
                aligned_allocator_adaptor<U, Alignment>& other)
                : Allocator(other.allocator()) {
            }

            allocator_type& allocator() {
                return static_cast<Allocator&>(*this);
            }

            const allocator_type& allocator() const {
                return static_cast<const Allocator&>(*this);
            }

            pointer allocate(size_type size) {
                std::size_t n1 = size * sizeof(value_type);
                std::size_t n2 = n1 + MaxAlign;
                CharAlloc a1(allocator());
                CharPtr p1 = a1.allocate(sizeof(p1) + n2);
                void* p2 = detail::addressof(*p1) + sizeof p1;
                align(MaxAlign, n1, p2, n2);
                void* p3 = static_cast<CharPtr*>(p2) - 1;
                ::new(p3) CharPtr(p1);
                return static_cast<pointer>(p2);
            }

            pointer allocate(size_type size, const_void_pointer hint) {
                std::size_t n1 = size * sizeof(value_type);
                std::size_t n2 = n1 + MaxAlign;
                CharPtr h1 = CharPtr();
                if (hint) {
                    h1 = *(static_cast<const CharPtr*>(hint) - 1);
                }
                CharAlloc a1(allocator());
#if !defined(BOOST_NO_CXX11_ALLOCATOR)
                CharPtr p1 = CharTraits::allocate(a1, sizeof(p1) +
                    n2, h1);
#else
                CharPtr p1 = a1.allocate(sizeof(p1) + n2, h1);
#endif
                void* p2 = detail::addressof(*p1) + sizeof p1;
                align(MaxAlign, n1, p2, n2);
                void* p3 = static_cast<CharPtr*>(p2) - 1;
                ::new(p3) CharPtr(p1);
                return static_cast<pointer>(p2);
            }

            void deallocate(pointer memory, size_type size) {
                CharPtr* p1 = reinterpret_cast<CharPtr*>(memory) - 1;
                CharPtr p2 = *p1;
                p1->~CharPtr();
                CharAlloc a1(allocator());
                a1.deallocate(p2, size * sizeof(value_type) +
                    MaxAlign + sizeof p2);
            }
        };

        template<class A1, class A2, std::size_t Alignment>
        inline bool operator==(const aligned_allocator_adaptor<A1,
            Alignment>& a, const aligned_allocator_adaptor<A2,
            Alignment>& b)
        {
            return a.allocator() == b.allocator();
        }

        template<class A1, class A2, std::size_t Alignment>
        inline bool operator!=(const aligned_allocator_adaptor<A1,
            Alignment>& a, const aligned_allocator_adaptor<A2,
            Alignment>& b)
        {
            return !(a == b);
        }
    }

    using alignment::aligned_allocator_adaptor;
}

#endif
