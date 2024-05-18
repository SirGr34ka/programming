#include <iostream>
#include <stdint.h>

int32_t division(int32_t num1, int32_t num2)
{
    bool sign = (num1 ^ num2) >> 31;
    int32_t quotient = 0;
    uint32_t abs_first = abs(num1), abs_second = abs(num2);

    for (uint32_t temp = abs_second; temp <= abs_first; temp += abs_second, ++quotient);

    if (sign)
    {
        quotient = ~quotient + 1;
    }

    return quotient;
}