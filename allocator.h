#pragma once

#include <corecrt.h>

template<class T>
struct Allocator 
{
    typedef T value_type;

    Allocator(){}

    template < class U > 
    Allocator( const Allocator< U >& other ){}

    T* allocate( size_t count_objects )
    {
        return static_cast< T* >( operator new( count_objects * sizeof( T ) ) );
    }

    void deallocate( T* ptr , size_t count_objects )
    {
        operator delete( ptr , count_objects );
    }
};

template<class T, class U>
bool operator==( const Allocator<T>& , const Allocator<U>& )
{
    return true;
}

template<class T, class U>
bool operator!=( const Allocator<T>& , const Allocator<U>& )
{
    return false;
}