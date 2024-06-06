#include <cassert>

#include "2d_mesh.h"

// Тест верного ввода с отрицательными числами
void test_correct_input_with_negative_numbers()
{
    assert( is_it_possible_to_get(-4, 20, 4, -5, 100) );

    return;
}

int main()
{
    test_correct_input_with_negative_numbers();
    
    return 0;
}