#include <iostream>
#include "convolution.h"

int main(int, char**)
{
    size_t m;
    size_t n;

    // Первая матрица
    std::cout << "Input matrix_1 rows: ";
    std::cin >> m;

    std::cout << "Input matrix_1 columns: ";
    std::cin >> n;

    Matrix matrix_1(m, n);

    std::cout << "Input matrix_1: ";
    std::cin >> matrix_1;

    std::cout << "matrix_1:" << std::endl;
    std::cout << matrix_1;

    // Вторая матрица
    std::cout << "Input matrix_2 rows: ";
    std::cin >> m;

    std::cout << "Input matrix_2 columns: ";
    std::cin >> n;

    Matrix matrix_2(m, n);

    std::cout << "Input matrix_2: ";
    std::cin >> matrix_2;

    std::cout << "matrix_2:" << std::endl;
    std::cout << matrix_2;

    Matrix* matrix_1_ptr = &matrix_1;
    Matrix* matrix_2_ptr = &matrix_2;

    // Свертка
    Convolution convolution(matrix_1_ptr, matrix_2_ptr);

    Matrix feature_map = convolution.getFeatureMap();

    std::cout << "Feature map:" << std::endl;
    std::cout << feature_map;
    
    return 0;
}