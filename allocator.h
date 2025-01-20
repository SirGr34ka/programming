#pragma once

#include <stdlib.h> //size_t, malloc, free
#include <new> // bad_alloc, bad_array_new_length
#include <memory>

template < typename T , size_t SIZE >
struct Allocator
{
    size_t size_in_bytes;
    std::shared_ptr< void* > pool_shared_ptr;
    
    typedef T value_type;

    Allocator()
    {
        size_in_bytes = SIZE * sizeof( T );
        pool_shared_ptr = std::make_shared< void* >();
        *pool_shared_ptr = operator new( size_in_bytes );

        if ( !( *pool_shared_ptr ) )
        {
            throw std::bad_alloc();
        }
    }

    // A converting copy constructor:
    template< typename U >
    Allocator( const Allocator< U , SIZE >& other ) noexcept : size_in_bytes( other.size_in_bytes ) , pool_shared_ptr( other.pool_shared_ptr )
    {
        return;
    }

    ~Allocator()
    {
        if ( pool_shared_ptr.use_count() == 1 )
        {
            operator delete( *pool_shared_ptr , size_in_bytes );

            size_in_bytes = 0;
            *pool_shared_ptr = nullptr;
        }
    }
    
    template< typename U >
    bool operator==( const Allocator< U , SIZE >& ) const noexcept
    {
        return true;
    }

    template< typename U >
    bool operator!=( const Allocator< U , SIZE >& ) const noexcept
    {
        return false;
    }

    template < typename U >
    struct rebind
    {
        typedef Allocator< U , SIZE > other;
    };

    T* allocate( const size_t n );
    void deallocate( T* const p , size_t ) noexcept;
};

template < typename T , size_t SIZE >
T* Allocator< T , SIZE >::allocate( const size_t n )
{
    if ( n == 0 )
    {
        return nullptr;
    }

    if ( n > static_cast< size_t >( -1 ) / sizeof( T ) )
    {
        throw std::bad_array_new_length();
    }

    void* const ptr = operator new( n * sizeof( T ) );

    if ( !ptr )
    {
        throw std::bad_alloc();
    }

    return static_cast< T* >( ptr );
}

template< typename T , size_t SIZE >
void Allocator< T , SIZE >::deallocate( T * const ptr , size_t n ) noexcept
{
    operator delete( ptr , n * sizeof( T ) );
}