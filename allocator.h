#pragma once

#include <iostream>

template<class T>
class Allocator 
{
    const float EXPANSION_COEFFICIENT = 1.5F;

    T* block_ptr;
    size_t capacity;
    size_t offset;

    size_t type_size;

    public:

    typedef T value_type;

    Allocator( size_t capacity_ = 10 )
    {
        capacity = capacity_;
        block_ptr = static_cast< T* >( operator new( capacity_ * sizeof( T ) ) );
        offset = 0;

        type_size = sizeof( T );
    }

    template < class U > 
    Allocator( const Allocator< U >& other )
    {
        capacity = other.capacity;
        block_ptr = other.block_ptr;
        offset = other.offset;
    }

    T* allocate( size_t count_objects )
    {
        if ( count_objects <= capacity - offset )
        {
            offset += count_objects;

            return block_ptr + offset - count_objects;
        }

        size_t new_capacity = static_cast< size_t >( static_cast< float >( capacity ) * EXPANSION_COEFFICIENT );

        if ( count_objects > new_capacity - offset )
        {
            throw std::bad_alloc();
        }

        T* new_block_ptr = static_cast< T* >( operator new( new_capacity * sizeof( T ) ) );

        for ( size_t i = 0 ; i < offset ; ++i )
        {
            *( new_block_ptr + i ) = *( block_ptr + i );
        }

        operator delete( block_ptr , offset );

        block_ptr = new_block_ptr;
        capacity = new_capacity;
        offset += count_objects;

        return block_ptr + offset - count_objects;
    }

    void deallocate( T* ptr , size_t count_objects )
    {
        operator delete( ptr , count_objects * sizeof( T ) );
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