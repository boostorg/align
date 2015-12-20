/*
(c) 2015 Glen Joseph Fernandes
<glenjofe -at- gmail.com>

Distributed under the Boost Software
License, Version 1.0.
http://boost.org/LICENSE_1_0.txt
*/
#define BOOST_ALIGN_USE_ALLOCATE
#include <boost/align/aligned_alloc.hpp>
#include <boost/align/is_aligned.hpp>
#include <boost/core/lightweight_test.hpp>
#include <cstdlib>
#include <cstring>

namespace boost {
namespace alignment {

void* allocate(std::size_t size)
{
    return std::malloc(size);
}

void deallocate(void* ptr)
{
    std::free(ptr);
}

} /* .alignment */
} /* .boost */

void test(std::size_t alignment)
{
    {
        void* p = boost::alignment::aligned_alloc(alignment,
            alignment);
        BOOST_TEST(p != 0);
        BOOST_TEST(boost::alignment::is_aligned(p, alignment));
        std::memset(p, 0, 1);
        boost::alignment::aligned_free(p);
    }
    {
        void* p = boost::alignment::aligned_alloc(alignment,
            alignment + 1);
        BOOST_TEST(p != 0);
        BOOST_TEST(boost::alignment::is_aligned(p, alignment));
        std::memset(p, 0, 1);
        boost::alignment::aligned_free(p);
    }
    if (alignment > 1) {
        void* p = boost::alignment::aligned_alloc(alignment,
            alignment - 1);
        BOOST_TEST(p != 0);
        BOOST_TEST(boost::alignment::is_aligned(p, alignment));
        std::memset(p, 0, 1);
        boost::alignment::aligned_free(p);
    } else {
        void* p = boost::alignment::aligned_alloc(alignment, 0);
        boost::alignment::aligned_free(p);
    }
}

int main()
{
    test(1);
    test(2);
    test(4);
    test(8);
    test(16);
    test(32);
    test(64);
    test(128);

    return boost::report_errors();
}
