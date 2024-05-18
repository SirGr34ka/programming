#include <iostream>
#include "division.h"

int main(int, char**)
{
    int32_t first, second;

    std::cout << "Input first number: ";
    std::cin >> first;

    std::cout << "Input second number: ";
    std::cin >> second;

    // Обработка исключения
    try
    {
        int32_t res = division(first, second);
        std::cout << "Division result: " << res;
    }
    catch(const char* err)
    {
        std::cerr << err << std::endl;
        return 1;
    }

    return 0;
}