#include <iostream>

#include "hash_table.h"

int main( int , char** )
{
    enrolled( "../students.txt" );

    std::string lastname;

    for ( size_t i = 0 ; i < 5 ; ++i )
    {
        std::cout << "Input student's lastname: ";
        std::cin >> lastname;

        unenrolled( lastname );
    }

    output();

    return 0;
}