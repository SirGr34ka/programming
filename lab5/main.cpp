#include <iostream>
#include "functions.h"

int main(int, char**)
{
    const int num = 3;

    // Обработка исключений
    try
    {
        std::cout << "Start" << std::endl;

        function1(num);

        std::cout << "End" << std::endl;
    }
    catch(const int& num)
    {
        std::cout << "num square: " << num << std::endl;
    }
    catch(const double& num)
    {
        std::cout << "Return double: " << num << std::endl;
    }
    catch(...)
    {
        std::cerr << "!!!" << std::endl;
    }
    
    return 0;
}