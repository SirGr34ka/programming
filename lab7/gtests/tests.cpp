#include <gtest/gtest.h>

#include "timing_difference.h"

// Проверка на верный ввод
TEST( TestDifference, correct_input )
{
    std::vector<std::string> timings{ "14:33" , "15:45" , "15:55" , "13:10" };
    EXPECT_EQ( minDifference( timings ), 10 );
}

// Проверка на вывод нуля
TEST( TestDifference, zero_output )
{
    std::vector<std::string> timings{ "14:33" , "15:45" , "15:45" , "13:10" };
    EXPECT_EQ( minDifference( timings ), 0 );
}

// Проверка на ввод пустого вектора
TEST( TestDifference, empty_vector )
{
    std::vector<std::string> timings{ };
    EXPECT_EQ( minDifference( timings ), -1 );
}

// Проверка на неверный формат
TEST( TestDifference, wrong_input )
{
    std::vector<std::string> timings{ "14:33" , "15:59" , "15:66" , "13:10" };
    EXPECT_EQ( minDifference( timings ), -1 );
}