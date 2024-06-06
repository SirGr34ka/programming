#include <cassert>

#include "2d_mesh.h"

// Тест ввода нулевого количества шагов
void test_zero_steps()
{
    assert( is_it_possible_to_get(0, 0, 0, 0, 0) );

    return;
}

int main()
{
    test_zero_steps();

    return 0;
}