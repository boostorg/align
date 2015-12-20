/*
(c) 2015 Glen Joseph Fernandes
<glenjofe -at- gmail.com>

Distributed under the Boost Software
License, Version 1.0.
http://boost.org/LICENSE_1_0.txt
*/
#include <boost/align/assume_aligned.hpp>

char test1(char* p)
{
    BOOST_ALIGN_ASSUME_ALIGNED(p, 1);
    return *p;
}

char test2(char* p)
{
    BOOST_ALIGN_ASSUME_ALIGNED(p, 2);
    return *p;
}

char test4(char* p)
{
    BOOST_ALIGN_ASSUME_ALIGNED(p, 4);
    return *p;
}

char test8(char* p)
{
    BOOST_ALIGN_ASSUME_ALIGNED(p, 8);
    return *p;
}

char test16(char* p)
{
    BOOST_ALIGN_ASSUME_ALIGNED(p, 16);
    return *p;
}

char test32(char* p)
{
    BOOST_ALIGN_ASSUME_ALIGNED(p, 32);
    return *p;
}

char test64(char* p)
{
    BOOST_ALIGN_ASSUME_ALIGNED(p, 64);
    return *p;
}

char test128(char* p)
{
    BOOST_ALIGN_ASSUME_ALIGNED(p, 128);
    return *p;
}

int main()
{
    return 0;
}
