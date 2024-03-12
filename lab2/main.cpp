#include <iostream>
#include <vector>

void sum(std::vector<unsigned int> &res, std::vector<unsigned int> &nums1, std::vector<unsigned int> &nums2)
{
    size_t size = nums2.size();

    if ((nums1.back() + nums2.back()) >> 31)
    {
        res.resize(size + 1);
    }
    else
    {
        res.resize(size);
    }

    for (size_t i = 0; i < size; ++i)
    {
        if ((nums1[i] + nums2[i]) >> 31)
        {
            res[i] += (nums1[i] + nums2[i]) & ~(1 << 31);
            ++res[i + 1];
        }
        else
        {
            res[i] += nums1[i] + nums2[i];
        }
    }

    return;
}

int main(int, char**)
{
    unsigned int input_1;
    std::vector<unsigned int> nums1{ 1073741827, 52, 8831 };
    std::vector<unsigned int> nums2{ 1073741824, 4342, 111 };
    std::vector<unsigned int> res;

    std::cout << "Input Fibonacci sequence element number: ";
    std::cin >> input_1;

    sum(res, nums1, nums2);

    for (size_t i = 0; i < 3; ++i)
    {
        std::cout << res[i] << " ";
    }

    std::cout << "\n";

    return 0;
}