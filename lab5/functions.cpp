#include <iostream>

void function1(const int&);
void function2(const int&);
void function3(const int&);
void function4(const int&);
void function5(const int&);

void function1(const int& num)
{
    std::cout << "Enter function1" << std::endl;

    function2(num);

    std::cout << "Out function1" << std::endl;

    return;
}

void function2(const int& num)
{
    std::cout << "Enter function2" << std::endl;

    if (num == 2)
    {
        throw num * num;
    }
    if (num == 6)
    {
        throw 2.54;
    }

    function3(num);

    std::cout << "Out function2" << std::endl;
    
    return;
}

void function3(const int& num)
{
    std::cout << "Enter function3" << std::endl;

    if (num == 3)
    {
        throw num * num;
    }

    function4(num);

    std::cout << "Out function3" << std::endl;
    
    return;
}

void function4(const int& num)
{
    std::cout << "Enter function4" << std::endl;

    function5(num);

    std::cout << "Out function4" << std::endl;
    
    return;
}

void function5(const int& num)
{
    std::cout << "Enter function5" << std::endl;
    std::cout << "Out function5" << std::endl;
    
    return;
}