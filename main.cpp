#include <fstream>
#include <iostream>

#include "containers.h"

int main(int, char **)
{
    try
    {
        
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