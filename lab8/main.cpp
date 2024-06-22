#include <iostream>

#include "hash_table.h"

int main( int , char** )
{
    enrolled( "../students.txt" );

    std::string lastname;

    while ( true )
    {
        std::cout << "Input student's lastname: ";
        std::cin >> lastname;

        if ( lastname == "end" )
        {
            break;
        }

        unenrolled( lastname );
    }

    output();

    return 0;
}