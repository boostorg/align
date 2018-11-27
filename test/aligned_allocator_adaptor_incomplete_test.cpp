/*
Copyright 2018 Glen Joseph Fernandes
(glenjofe@gmail.com)

Distributed under the Boost Software License, Version 1.0.
(http://www.boost.org/LICENSE_1_0.txt)
*/
#include <boost/align/aligned_allocator_adaptor.hpp>

template<class T>
class A {
public:
    typedef T value_type;
    typedef T* pointer;
    typedef std::size_t size_type;
    typedef std::ptrdiff_t difference_type;

    template<class U>
    struct rebind {
        typedef A<U> other;
    };

    A() { }

    template<class U>
    A(const A<U>&) { }

    T* allocate(std::size_t size) {
        return static_cast<T*>(::operator new(sizeof(T) * size));
    }

    void deallocate(T* ptr, std::size_t) {
        ::operator delete(ptr);
    }
};

template<class T, class U>
inline bool
operator==(const A<T>&, const A<U>&)
{
    return true;
}

template<class T, class U>
inline bool
operator!=(const A<T>& a, const A<U>& b)
{
    return !(a == b);
}

struct S;

void value_test()
{
    boost::alignment::aligned_allocator_adaptor<A<S> > a;
    (void)a;
}

void rebind_test()
{
    boost::alignment::aligned_allocator_adaptor<A<int> >::rebind<S>::other a;
    (void)a;
}
