#include <iostream>
#include <string>

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

    formatting_adress(adress);

    std::cout << "After formatting: " << adress << "\n";

    return 0;
}