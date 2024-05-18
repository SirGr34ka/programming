#include <iostream>
#include "division.h"

int main(int, char**)
{
    int32_t first, second;

    std::cout << "Input first number: ";
    std::cin >> first;

    std::cout << "Input second number: ";
    std::cin >> second;

    // Обработка деления на ноль
    try
    {
        if (second == 0)
        {
            throw "Can't devide by zero!";
        }
    }
    catch(const char* err)
    {
        std::cerr << err << std::endl;
        return 1;
    }

    // Если все нормально, то делим и выводим частное
    std::cout << "Quotient: " << division(first, second) << std::endl;

    return 0;
}