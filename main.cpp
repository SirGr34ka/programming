#include <iostream>

#include <vector>

#include "containers.h"

int main(int, char **)
{
    try
    {
        ListContainer< std::vector< int > > container;

        std::vector< int > vec1{ 1 , 11 , 111 };
        std::vector< int > vec2{ 2 , 22 , 222 };
        std::vector< int > vec3{ 3 , 33 , 333 };

        container.push_back( vec1 );
        container.push_back( vec3 );
        container.insert( 1 , vec2 );
        container.insert( 2 , vec2 );

        std::cout << container.size() << std::endl;

        for ( size_t i = 0 ; i < container.size() ; ++i )
        {
            for ( int num : container[i] )
            {
                std::cout << num << " ";
            }

            std::cout << std::endl;
        }
        container.erase( 0 , 5 );

        std::cout << container.size() << std::endl;

        for ( size_t i = 0 ; i < container.size() ; ++i )
        {
            for ( int num : container[i] )
            {
                std::cout << num << " ";
            }

            std::cout << std::endl;
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