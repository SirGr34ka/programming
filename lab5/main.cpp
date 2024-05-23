#include <iostream>
#include "fibonacciSequence.h"

int main(int, char**)
{
    size_t input_1;
    
    std::cout << "Input Fibonacci sequence element number: ";
    std::cin >> input_1;

    fibonacci_output(input_1);
    
    return 0;
}