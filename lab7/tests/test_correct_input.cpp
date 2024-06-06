#include <cassert>

#include "2d_mesh.h"

// Тест верного ввода
void test_correct_input()
{
    assert( is_it_possible_to_get(15, 20, 20, 30, 50) );

    return;
}

int main()
{
    test_correct_input();
    
    return 0;
}