#include <iostream>
#include <cassert>

#include "test.h"

int main(int, char**)
{
    std::cout << "test_zero_seconds..." << std::flush;
    test_zero_seconds();

    std::cout << "test_correct_input..." << std::flush;
    test_correct_input();

    std::cout << "test_incorrect_input..." << std::flush;
    test_incorrect_input();

    return 0;
}