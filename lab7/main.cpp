#include <iostream>
#include <cassert>

#include "clean_room.h"

void test_correct_input()
{
    assert( who_is_going_to_clean_the_room( 5, 6 ) == 5 );
}

void test_incorrect_input()
{
    assert( who_is_going_to_clean_the_room( -15, -4 ) != 0 );
}

int main(int, char**)
{
    std::cout << "test_correct_input..." << std::flush;
    test_correct_input();
    std::cout << "OK" << std::endl;

    std::cout << "test_incorrect_input..." << std::flush;
    test_incorrect_input();
    std::cout << "OK" << std::endl;
}