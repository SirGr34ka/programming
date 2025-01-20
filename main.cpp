#include <iostream>

#include <vector>
#include <map>

#include "containers.h"
#include "allocator.h"

size_t factorial( size_t n )
{
    size_t result = 1;

    for ( size_t i = 2 ; i <= n ; ++i )
    {
        result *= i;
    }

    return result;
}

int main(int, char **)
{
    try
    {
        const size_t MAP_SIZE = 10;
        std::map< int , int > map1;

        for ( size_t i = 1 ; i <= MAP_SIZE ; ++i )
        {
            std::pair< const int , int > temp { i , static_cast< int >( factorial( i ) ) };
            map1.insert( temp );
        }

        for ( auto iter = map1.begin() ; iter != map1.end() ; ++iter )
        {
            std::cout << (*iter).first << ": " << (*iter).second << std::endl;
        }

        typedef Allocator< std::pair< const int , int > , 10ull > Alloc;

        std::map< const int , int , std::less< int > , Alloc > map2;

        for ( size_t i = 1 ; i <= MAP_SIZE ; ++i )
        {
            map2.insert( { i , static_cast< int >( factorial( i ) ) } );
        }

        for ( auto iter = map2.begin() ; iter != map2.end() ; ++iter )
        {
            std::cout << iter->first << ": " << iter->second << std::endl;
        }
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch( const char* message )
    {
        std::cerr << message << std::endl;
    }

    return 0;
}