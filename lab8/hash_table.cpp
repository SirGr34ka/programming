#include <math.h>

#include "hash_table.h"

HashTable::HashTable()
{
    prices = new size_t [ hash_value ];
}

HashTable::HashTable( const size_t size )
{
    this->size = size;

    hash_value = ( size_t )( size * 1.5 );
    prices = new size_t [ hash_value ];
}

size_t HashTable::getHash( const std::string& str ) const
{
    size_t hash = 0;

    for ( size_t i = 0 ; i < str.size() ; ++i )
    {
        hash += ( str[i] * ( size_t )( pow( log( i + 1488 ) , i ) ) ) % 100000;
    }

    return hash % hash_value;
}

void HashTable::pushPrice( const std::string& product , const size_t price )
{
    size_t hash = getHash( product );
    prices[ hash ] = price;
    ++capacity;

    return;
}

void HashTable::popPrice( const std::string& product )
{
    if ( capacity == 0 )
    {
        std::cout << "Can't delete position in empty table!" << std::endl;
        return;
    }
    
    size_t hash = getHash( product );

    if ( prices[ hash ] == 0 )
    {
        std::cout << "No position to delete!" << std::endl;
        return;
    }

    prices[ hash ] = 0;
    --capacity;

    return;
}

size_t HashTable::searchPrice( const std::string& product ) const
{
    size_t hash = getHash( product );
    size_t price = prices[ hash ];

    if ( price == 0 )
    {
        std::cout << "No position to delete!" << std::endl;
    }

    return price;
}

bool HashTable::isEmpty() const
{
    return capacity == 0;
}

size_t HashTable::getCapacity() const
{
    return capacity;
}

HashTable::~HashTable()
{
    delete[] prices;
}