#include <iostream>

#include "hash_table.h"

int main( int , char** )
{
    enrolled( "../students.txt" );

    std::string lastname;

    while ( lastname == "end" )
    {
        unenrolled( lastname );
        
        std::cout << "Input student's lastname: ";
        std::cin >> lastname;
    }

    output();

    return 0;
}