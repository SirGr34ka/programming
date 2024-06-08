#include <gtest/gtest.h>

#include "equation_solution.h"

// Проверка на верный ввод
TEST( TestEquation, correct_equation )
{
    EXPECT_EQ( getSolution( "x+2x+1-2=6+x-1" ), "x=3" );
}

// Проверка на верный вывод бесконечного числа решений
TEST( TestEquation, infinite_enquation )
{
    EXPECT_EQ( getSolution( "5+x-2x=15-x-10" ), "Infinite" );
}

// Проверка на верный вывод отсутствия решений
TEST( TestEquation, no_solution_enquation )
{
    EXPECT_EQ( getSolution( "5x+3+9-3x=2x+4-5" ), "NO" );
}