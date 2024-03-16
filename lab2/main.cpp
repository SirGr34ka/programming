#include <iostream>
#include <vector>

/*
* @brief
* Сумма соответствующих элементов массивов с переносом 10 разряда в следующий элемент вектора
* 
* @param res
* вектор, в который будет записываться результат вычислений
*
* @param nums1
* вектор, в котором хранится поэлементно первое число
*
* @param nums1
* вектор, в котором хранится поэлементно второе число
*/
void sum(std::vector<unsigned int> &res, std::vector<unsigned int> &nums1, std::vector<unsigned int> &nums2)
{
    size_t size = nums2.size();
    unsigned int temp = nums1[size - 2] + nums2[size - 2]; // Сумма последних значащих элементов

    res.clear();

    // Вычисление кол-ва эл-ов в оезультирующем векторе
    if ((temp / 1'000'000'000) > 0)
    {
        res.resize(size + 1);
    }
    else
    {
        res.resize(size);
    }

    // Сложение соответствующих элементов векторов nums1, nums2
    for (size_t i = 0; i < size - 1; ++i)
    {
        temp = nums1[i] + nums2[i];
        res[i] += temp % 1'000'000'000;

        // Перенос в следующий элемент 10 разряда
        if ((temp / 1'000'000'000) > 0)
        {
            res[i + 1] = temp / 1'000'000'000;
        }
    }

    return;
}

/*
* @brief
* Вычисление эл-ов последовательности Фибоначчи
*
* @param num
* номер элеманта в последовательности, который нужно найти
* 
* @param elements
* вектор, который заполняется элементами последовательности
*/
void fibonacci_sequence(size_t num, std::vector<std::vector<unsigned int>> &elements)
{
    std::vector<unsigned int> res(2);

    elements[0] = res;
    elements[1] = res;

    res[0] = 1;
    elements[2] = res;

    // Заполнение элементами последовательности вектора elements
    for (size_t i = 3; i <= num; ++i)
    {
        sum(res, elements[i - 2], elements[i - 1]);
        elements[i] = res;
    }
    
    return;
}

int main(int, char**)
{
    size_t input_1;
    std::vector<unsigned int> res;

    std::cout << "Input Fibonacci sequence element number: ";
    std::cin >> input_1;
    
    // Инициализация вектора, в котором будут храниться элементы последовательности
    std::vector<std::vector<unsigned int>> fibonacci_sequence_elements(input_1 + 1, res);

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