/*
 Copyright (c) 2014 Glen Joseph Fernandes
 glenfe at live dot com

 Distributed under the Boost Software License,
 Version 1.0. (See accompanying file LICENSE_1_0.txt
 or copy at http://boost.org/LICENSE_1_0.txt)
*/
#include <boost/config.hpp>
#include <boost/align/align.hpp>
#include <boost/align/is_aligned.hpp>
#include <boost/detail/lightweight_test.hpp>

#if !defined(BOOST_NO_ALIGNMENT)

void test(std::size_t alignment, char* buffer)
{
    {
        std::size_t n = alignment;
        void* p = buffer;
        void* q = boost::align(alignment, 0, p, n);
        BOOST_TEST(q == p);
        BOOST_TEST(q == buffer);
        BOOST_TEST(boost::is_aligned(alignment, q));
        BOOST_TEST(n == alignment);
    }
    {
        std::size_t n = alignment - 1;
        void* p = &buffer[1];
        void* q = boost::align(alignment, 1, p, n);
        BOOST_TEST(q == 0);
        BOOST_TEST(p == &buffer[1]);
        BOOST_TEST(n == alignment - 1);
    }
    {
        std::size_t n = alignment;
        void* p = &buffer[1];
        void* q = boost::align(alignment, 0, p, n);
        BOOST_TEST(q == p);
        BOOST_TEST(q == &buffer[alignment]);
        BOOST_TEST(boost::is_aligned(alignment, q));
        BOOST_TEST(n == 1);
    }
}

int main()
{
    {
        BOOST_ALIGNMENT(1) char s[2];
        test(1, s);
    }
    {
        BOOST_ALIGNMENT(2) char s[3];
        test(2, s);
    }
    {
        BOOST_ALIGNMENT(4) char s[5];
        test(4, s);
    }
    {
        BOOST_ALIGNMENT(8) char s[9];
        test(8, s);
    }
    {
        BOOST_ALIGNMENT(16) char s[17];
        test(16, s);
    }
    {
        BOOST_ALIGNMENT(32) char s[33];
        test(32, s);
    }
    {
        BOOST_ALIGNMENT(64) char s[65];
        test(64, s);
    }
    {
        BOOST_ALIGNMENT(128) char s[129];
        test(128, s);
    }

    return boost::report_errors();
}

#else

int main()
{
    return 0;
}

#endif
