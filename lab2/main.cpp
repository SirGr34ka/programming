#include <iostream>
#include <vector>
#include "bigint.h"

/**
 * @brief
 * Вычисление последовательности Фибоначчи
 * 
 * @param number
 * номер элемента в последовательности
 * 
 * @return
 * Элемент последовательности под номером number
*/
bigint fibonacci_sequence(const unsigned int number) {
    std::vector<bigint> fibonacci_sequence_elements(number + 1);
    fibonacci_sequence_elements[1] = 0, fibonacci_sequence_elements[2] = 1;

    for (unsigned int i = 3; i <= number; ++i)
        fibonacci_sequence_elements[i] = fibonacci_sequence_elements[i - 2] + fibonacci_sequence_elements[i - 1];

    return fibonacci_sequence_elements[number];
}

int main(int, char**) {
    unsigned int input_1;

    std::cout << "Input Fibonacci sequence element number: ";
    std::cin >> input_1;

    std::cout << fibonacci_sequence(input_1) << std::endl;

    return 0;
}