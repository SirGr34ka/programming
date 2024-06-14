#include <gtest/gtest.h>

#include "2d_mesh.h"

// Проверка на верный ввод
TEST( TestMesh , correct_input )
{
    ASSERT_TRUE( is_it_possible_to_get( 4 , 5 ) );
}

// Проверка на верный вывод, где входные данные не являются степенями двойки
TEST( TestMesh , not_power_of_two_correct_output )
{
    ASSERT_TRUE( is_it_possible_to_get( 9 , 5 ) );
}

// Проверка на ложный вывод
TEST( TestMesh , false_output )
{
    ASSERT_FALSE( is_it_possible_to_get( 0 , 3 ) );
}

