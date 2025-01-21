#pragma once

#include <stdlib.h> //size_t, malloc, free
#include <new> // bad_alloc, bad_array_new_length
#include <memory>

#include <tuple>

template < typename T >
struct Allocator
{
    size_t size_;
    size_t size_in_bytes;
    std::shared_ptr< void* > pool_shared_ptr;
    std::shared_ptr< bool[] > chunks_shared_ptr;
    
    typedef T value_type;

    Allocator( size_t size )
    {
        size_ = size + 33ull;
        size_in_bytes = ( size_ ) * ( sizeof( T ) + 32ull );
        pool_shared_ptr = std::make_shared< void* >();
        *pool_shared_ptr = operator new( size_in_bytes );

        if ( !( *pool_shared_ptr ) )
        {
            throw std::bad_alloc();
        }

        chunks_shared_ptr = std::make_shared< bool[] >( size_ );

        for ( size_t i = 0 ; i < size_ ; ++i )
        {
            chunks_shared_ptr[ i ] = false;
        }
    }

    // A converting copy constructor:
    template< typename U >
    Allocator( const Allocator< U >& other ) noexcept :
    size_( other.size_ ) , size_in_bytes( other.size_in_bytes ) , pool_shared_ptr( other.pool_shared_ptr ) , chunks_shared_ptr( other.chunks_shared_ptr )
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
    bool operator==( const Allocator< U >& ) const noexcept
    {
        return true;
    }

    template< typename U >
    bool operator!=( const Allocator< U >& ) const noexcept
    {
        return false;
    }

    T* allocate( const size_t n );
    void deallocate( T* const p , size_t ) noexcept;
};

template < typename T >
T* Allocator< T >::allocate( const size_t n )
{
    if ( n == 0 )
    {
        return nullptr;
    }

    if ( n > static_cast< size_t >( -1 ) / sizeof( T ) )
    {
        throw std::bad_array_new_length();
    }

    T* ptr = nullptr;

    size_t count = 0 , i = 0;

    while ( ( count < n ) && ( i < size_ ) )
    {
        if ( !chunks_shared_ptr[ i ] )
        {
            ++count;
        }
        else
        {
            count = 0;
        }

        ++i;
    }

    if ( count == n )
    {
        ptr = static_cast< T* >( *pool_shared_ptr ) + ( i - count );

        for ( size_t j = 0 ; j < count ; ++j )
        {
            chunks_shared_ptr[ ( i - count ) + j ] = true;
        }
    }
    else
    {
        throw "Out of memory!";
    }

    return ptr;
}

template< typename T >
void Allocator< T >::deallocate( T * const ptr , size_t n ) noexcept
{
    size_t diff = ptr - static_cast< T* >( *pool_shared_ptr );

    for ( size_t i = 0 ; i < n ; ++i )
    {
        chunks_shared_ptr[ diff + i ] = false;
    }
}