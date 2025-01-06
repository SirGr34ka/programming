#pragma once

#include <iostream>

template< typename T >
class Allocator 
{
    void* block_ptr;

    public:

    typedef T value_type;

    Allocator()
    {
        block_ptr = nullptr;
    }

    template < class U > 
    Allocator( const Allocator< U >& other )
    {
        block_ptr = nullptr;
    }

    T* allocate( size_t count_objects )
    {
        if ( !block_ptr )
        {
            block_ptr = operator new( 10ull );
        }

        return static_cast< T* >( operator new( count_objects * sizeof( T ) ) );
    }

    void deallocate( T* ptr , size_t count_objects )
    {
        if ( block_ptr )
        {
            operator delete( block_ptr );
            block_ptr = nullptr;
        }

        operator delete( ptr , count_objects * sizeof( T ) );
    }

    ~Allocator(){}
};

template< typename T , typename U >
bool operator ==( const Allocator< T >& , const Allocator< U >& )
{
    return true;
}

template< typename T , typename U >
bool operator !=( const Allocator< T >& , const Allocator< U >& )
{
    return false;
}