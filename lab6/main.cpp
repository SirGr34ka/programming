#include <iostream>
#include "matrix.h"

int main(int, char**)
{
    Matrix matrix_1;

    std::cout << "Input matrix_1: ";
    std::cin >> matrix_1;

    Matrix matrix_2;

    std::cout << "Input matrix_2: ";
    std::cin >> matrix_2;

    Matrix result = matrix_1 * 5;

    std::cout << "matrix_1 * 5:" << std::endl;
    std::cout << result;
    
    return 0;
}