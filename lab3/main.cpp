#include <iostream>
#include <vector>
#include <string>
#include <sstream>

/**
 * @brief
 * Проверяет на валидность IP адрес
 * 
 * @param adress
 * IP адрес
 * 
 * @return
 * true, если адрес валиден, иначе - false
*/
bool check_ip(std::string& adress)
{
    size_t cnt = 0;
    std::string num;
    std::stringstream temp(adress.c_str());

    for (char simbol: adress)
    {
        if (simbol == '.')
        {
            ++cnt;
        }
    }

    if (cnt != 3)
    {
        return false;
    }
    else
    {
        while (std::getline(temp, num, '.'))
        {
            if (stoi(num) > 255)
            {
                return false;
            }
        }
    }

    return true;
}

/**
 * @brief
 * Функция форматирует IPv4 адрес, заменяя "." на "[.]"
 * 
 * @param adress
 * адрес, который нужно отформатировать
*/
void formatting_adress(std::string &adress)
{
    size_t index = 0; // Индекс точки в адресе
    std::string replacement = "[.]"; // Замена "."

    for (size_t i = 0; i < 3; ++i, index += 2)
    {
        index = adress.find('.', index); // Находит индекс следующей точки
        adress.replace(index, 1, replacement); // Заменяет точку на замену
    }

    return;
}

int main(int, char**){
    std::string adress;

    std::cout << "Enter IPv4 adress: ";
    std::cin >> adress;

    if (check_ip(adress))
    {
        formatting_adress(adress);
        std::cout << "After formatting: " << adress << "\n";
    }
    else
    {
        std::cout << "Invalid adress\n";
    }
    
    return 0;
}