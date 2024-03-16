#include <iostream>
#include <vector>

void sum(std::vector<unsigned int> &res, std::vector<unsigned int> &nums1, std::vector<unsigned int> &nums2)
{
    size_t size = nums2.size();
    unsigned int temp = nums1[size - 2] + nums2[size - 2];

    res.clear();

    if ((temp / 1'000'000'000) > 0)
    {
        res.resize(size + 1);
    }
    else
    {
        res.resize(size);
    }

    for (size_t i = 0; i < size - 1; ++i)
    {
        temp = nums1[i] + nums2[i];
        res[i] += temp % 1'000'000'000;

        if ((temp / 1'000'000'000) > 0)
        {
            res[i + 1] = temp / 1'000'000'000;
        }
    }

    return;
}

void fibonacci_sequence(size_t num, std::vector<std::vector<unsigned int>> &elements)
{
    std::vector<unsigned int> res(2);

    elements[0] = res;
    elements[1] = res;

    res[0] = 1;
    elements[2] = res;

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
    
    std::vector<std::vector<unsigned int>> fibonacci_sequence_elements(input_1 + 1, res);

    fibonacci_sequence(input_1, fibonacci_sequence_elements);

    std::vector<unsigned int> element = fibonacci_sequence_elements[input_1];

    for (size_t i = element.size() - 1; i > 0; --i)
    {
        std::cout << element[i - 1];
    }

    std::cout << std::endl;

    return 0;
}