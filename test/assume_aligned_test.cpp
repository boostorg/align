/*
 (c) 2015 Glen Joseph Fernandes
 glenjofe at gmail dot com

 Distributed under the Boost Software
 License, Version 1.0.
 http://boost.org/LICENSE_1_0.txt
*/
#include <boost/align/assume_aligned.hpp>
#include <cstddef>

template<std::size_t Alignment>
void test(void* p = 0)
{
    BOOST_ALIGN_ASSUME_ALIGNED(p, Alignment);
    (void)p;
}

int main()
{
    test<1>();
    test<2>();
    test<4>();
    test<8>();
    test<6>();
    test<32>();
    test<64>();
    test<128>();
    return 0;
}
