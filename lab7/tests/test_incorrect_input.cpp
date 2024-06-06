#include <cassert>

#include "2d_mesh.h"

// Тест неверного ввода
void test_incorrect_input()
{
    assert( !(is_it_possible_to_get(15, 20, 20, 30, 4)) );

    return;
}

int main()
{
    test_incorrect_input();
    
    return 0;
}