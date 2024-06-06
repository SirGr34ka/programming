#include <iostream>
#include <cassert>

#include "test.h"
#include "clean_room.h"

void test_zero_seconds()
{
    const int n = 15, time = 0;
    const size_t result = who_is_going_to_clean_the_room( n, time );
    assert( result == 1 );

    std::cout << "OK" << std::endl;
    std::cout << "who_is_going_to_clean_the_room( " << n << ", " << time << " ): " << result << std::endl;
}

void test_correct_input()
{
    const int n = 5, time = 15;
    const size_t result = who_is_going_to_clean_the_room( n, time );
    assert( result == 2 );

    std::cout << "OK" << std::endl;
    std::cout << "who_is_going_to_clean_the_room( " << n << ", " << time << " ): " << result << std::endl;
}

void test_incorrect_input()
{
    const int n = 0, time = -4;
    const size_t result = who_is_going_to_clean_the_room( n, time );
    assert( result == 0 );

    std::cout << "OK" << std::endl;
    std::cout << "who_is_going_to_clean_the_room( " << n << ", " << time << " ): " << result << std::endl;
}