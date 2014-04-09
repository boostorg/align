/*
 Copyright (c) 2014 Glen Joseph Fernandes
 glenfe at live dot com

 Distributed under the Boost Software License,
 Version 1.0. (See accompanying file LICENSE_1_0.txt
 or copy at http://boost.org/LICENSE_1_0.txt)
*/
#include <boost/align/aligned_allocator_adaptor.hpp>
#include <boost/align/is_aligned.hpp>
#include <boost/detail/lightweight_test.hpp>
#include <cstring>

template<class T, std::size_t Alignment = 1>
struct adaptor {
    typedef boost::aligned_allocator_adaptor<std::allocator<T>,
        Alignment> type;
};

template<std::size_t Alignment>
void test_allocate()
{
    {
        typename adaptor<int, Alignment>::type a;
        int* p = a.allocate(1);
        BOOST_TEST(p != 0);
        BOOST_TEST(boost::is_aligned(Alignment, p));
        std::memset(p, 0, 1);
        a.deallocate(p, 1);
    }
    {
        typename adaptor<int, Alignment>::type a;
        int* p1 = a.allocate(1);
        int* p2 = a.allocate(1, p1);
        BOOST_TEST(p2 != 0);
        BOOST_TEST(boost::is_aligned(Alignment, p2));
        std::memset(p2, 0, 1);
        a.deallocate(p2, 1);
        a.deallocate(p1, 1);
    }
    {
        typename adaptor<int, Alignment>::type a;
        int* p = a.allocate(0);
        a.deallocate(p, 0);
    }
}

template<std::size_t Alignment>
void test_construct()
{
    typename adaptor<int, Alignment>::type a;
    int* p = a.allocate(1);
    a.construct(p, 1);
    BOOST_TEST(*p == 1);
    a.destroy(p);
    a.deallocate(p, 1);
}

template<std::size_t Alignment>
void test_constructor()
{
    {
        typename adaptor<char, Alignment>::type a1;
        typename adaptor<int, Alignment>::type a2(a1);
        BOOST_TEST(a2 == a1);
    }
    {
        std::allocator<int> a1;
        typename adaptor<int, Alignment>::type a2(a1);
        BOOST_TEST(a2.allocator() == a1);
    }
}

template<std::size_t Alignment>
void test_rebind()
{
    typedef typename adaptor<char, Alignment>::type allocator;
    allocator a1;
    typename allocator::template rebind<int>::other a2(a1);
    BOOST_TEST(a2 == a1);
}

template<std::size_t Alignment>
void test()
{
    test_allocate<Alignment>();
    test_construct<Alignment>();
    test_constructor<Alignment>();
    test_rebind<Alignment>();
}

int main()
{
    test<1>();
    test<2>();
    test<4>();
    test<8>();
    test<16>();
    test<32>();
    test<64>();
    test<128>();

    return boost::report_errors();
}
