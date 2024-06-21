#include <iostream>

#include "hash_table.h"

int main( int , char** )
{
    HashTable products( 5 );

    std::cout << "Is table empty: " << products.isEmpty() << std::endl;

    products.pushPrice( "brics" , 169 );
    products.pushPrice( "cement" , 69 );
    products.pushPrice( "wood" , 79 );

    std::cout << "Cement price: " << products.searchPrice( "cement" ) << std::endl;

    products.popPrice( "cement" );

    std::cout << "Cement price: " << products.searchPrice( "cement" ) << std::endl;
    std::cout << "Table capacity: " << products.getCapacity() << std::endl;
    std::cout << "Is table empty: " << products.isEmpty() << std::endl;

    return 0;
}