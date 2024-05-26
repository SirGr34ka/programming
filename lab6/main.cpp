#include <iostream>
#include "matrix.h"

int main(int, char**)
{
    Matrix matrix_1;

    std::cout << "Input matrix_1: ";
    std::cin >> matrix_1;

    std::cout << "matrix_1 max num: " << std::endl;
    std::cout << matrix_1.max();
    
    return 0;
}