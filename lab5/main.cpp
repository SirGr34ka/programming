#include <iostream>
#include "functions.h"

int main(int, char**)
{
    const int num = 3;

    try
    {
        std::cout << "Start" << std::endl;

        function1(num);

        std::cout << "End" << std::endl;
    }
    catch(int& num)
    {
        std::cout << "num square: " << num << std::endl;
    }
    catch(double& num)
    {
        std::cout << "Return double: " << num << std::endl;
    }

    return 0;
}