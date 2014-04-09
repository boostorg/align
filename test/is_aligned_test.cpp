/*
 Copyright (c) 2014 Glen Joseph Fernandes
 glenfe at live dot com

 Distributed under the Boost Software License,
 Version 1.0. (See accompanying file LICENSE_1_0.txt
 or copy at http://boost.org/LICENSE_1_0.txt)
*/
#include <boost/config.hpp>
#include <boost/align/is_aligned.hpp>
#include <boost/detail/lightweight_test.hpp>

#if !defined(BOOST_NO_ALIGNMENT)

int main()
{
    {
        BOOST_ALIGNMENT(1) char s[1];
        BOOST_TEST(boost::is_aligned(1, &s[0]));
    }
    {
        BOOST_ALIGNMENT(2) char s[2];
        BOOST_TEST(boost::is_aligned(2, &s[0]));
        BOOST_TEST(!boost::is_aligned(2, &s[1]));
    }
    {
        BOOST_ALIGNMENT(4) char s[4];
        BOOST_TEST(boost::is_aligned(4, &s[0]));
        BOOST_TEST(!boost::is_aligned(4, &s[1]));
    }
    {
        BOOST_ALIGNMENT(8) char s[8];
        BOOST_TEST(boost::is_aligned(8, &s[0]));
        BOOST_TEST(!boost::is_aligned(8, &s[1]));
    }
    {
        BOOST_ALIGNMENT(16) char s[16];
        BOOST_TEST(boost::is_aligned(16, &s[0]));
        BOOST_TEST(!boost::is_aligned(16, &s[1]));
    }
    {
        BOOST_ALIGNMENT(32) char s[32];
        BOOST_TEST(boost::is_aligned(32, &s[0]));
        BOOST_TEST(!boost::is_aligned(32, &s[1]));
    }
    {
        BOOST_ALIGNMENT(64) char s[64];
        BOOST_TEST(boost::is_aligned(64, &s[0]));
        BOOST_TEST(!boost::is_aligned(64, &s[1]));
    }
    {
        BOOST_ALIGNMENT(128) char s[128];
        BOOST_TEST(boost::is_aligned(128, &s[0]));
        BOOST_TEST(!boost::is_aligned(128, &s[1]));
    }

    return boost::report_errors();
}

#else

int main()
{
    return 0;
}

#endif
