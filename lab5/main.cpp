#include <iostream>
#include "fibonacciSequence.h"

int main() {
    size_t input_1;

    std::cout << "Input Fibonacci sequence element number: ";
    std::cin >> input_1;

    // Инициализация вектора, в котором будут храниться элементы последовательности
    std::vector<std::vector<unsigned int>> fibonacci_sequence_elements(input_1 + 1);

    fibonacci_sequence(input_1, fibonacci_sequence_elements);

    // input_1-й элемент последовательности
    std::vector<unsigned int> element = fibonacci_sequence_elements[input_1];

    // Вывод элемента
    for (size_t i = element.size() - 1; i > 0; --i)
    {
        std::cout << element[i - 1];
    }

    std::cout << std::endl;

    return 0;
}