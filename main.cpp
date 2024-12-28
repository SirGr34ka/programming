#include <iostream>

#include <vector>
#include <map>

#include "containers.h"
#include "allocator.h"

int main(int, char **)
{
    try
    {
        std::map< int , int , std::less< int > Allocator< std::pair< int , int > > > mapchik { { 1 , 2 } , { 3 , 4 } , { 5 , 6 } };

        for ( auto iter = mapchik.begin() ; iter != mapchik.end() ; ++iter )
        {
            std::cout << (*iter).first << ';' << (*iter).second << ' ' << std::endl;
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