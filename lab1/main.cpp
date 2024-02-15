#include <iostream>
#include <string>

/**
 * @brief Функция переводит десятичное число в нужную систему счисления (3 лаба 1 задание)
 *  
 * @param osn_ss Основание системы счисления, в которую нужно перевести
 * @param num Число в десятичной системы счисления
 * 
 * @return new_num - Число num в osn_ss системе счисления
*/
std::string convert(unsigned int osn_ss, unsigned int num)
{
    std::string new_num = "", alphabet = "0123456789abcdef";

    while (num > 0) {
        new_num = alphabet[num % osn_ss] + new_num;
        num /= osn_ss;
    }

    return new_num;
}

/**
 * @brief Функция возводит двойку в нужную степень (4 лаба 1 задание)
 * 
 * @param pow Степень, в которую нужно возвести двойку
*/
void sec_pow(unsigned int& pow)
{
    int num = 1 << pow;
    std::cout << num << "\n";
    std::cout << std::oct << num << "\n";
    std::cout << std::hex << num << "\n";
    std::cout << std::dec;
}

/**
 * @brief Функция из полученного массива Z(N) составляет и выводит на экран новый массив P(M), включив в него только числа из Z, которые принадлежат интервалу [-8;3],
 * при этом положительные числа уменьшает в 2 раза, отрицательные – возводит в квадрат, нулевые – оставляет без изменения. Все числа вне этого интервала суммирует и выводит
 * на экран сумму.
 * 
 * @param m Кол-во элементов в массиве P
 * @param n Кол-во элементов в массиве Z
 * @param z указатель на массив Z
*/
void form_new_arr(int m, const int n, int* z)
{
    int cnt = 0, sum = 0;
    int* p = new int[m];

    for (int i = 0; i < n; ++i) {
        if ((*(z + i) >= -8) && (*(z + i) <= 3)) {
            *(p + cnt) = *(z + i) >= 0 ? *(z + i) / 2 : *(z + i) * *(z + i);
            ++cnt;
        }
        else
            sum += *(z + i);
    }

    std::cout << "Сумма чисел вне интервала: " << sum << "\n";

    std::cout << "P = {" << *p;

    for (int i = 1; i < m; i++)
        std::cout << "; " << *(p + i);

    std::cout << "}\n";

    delete[] p;
}

int main() {
    setlocale(LC_ALL, "Russian");

    // 3 лаба 1 задание
    unsigned int osn_ss, num;

    std::cout << "Введите основание СС в которую нужно перевести: ";
    std::cin >> osn_ss;
    std::cout << "Введите число x: ";
    std::cin >> num;
    std::cout << num << "(10) = " << convert(osn_ss, num) << "(" << osn_ss << ")\n\n";

    // 4 лаба 1 задание
    unsigned int pow;

    std::cout << "Введите степень двойки n: ";
    std::cin >> pow;
    sec_pow(pow);
    std::cout << "\n";

    // 5 лаба 2 задание
    const int n = 10;
    int m = 0;
    int z[n]{};

    for (int i = 0; i < n; i++) {
        std::cout << "Введите " << i + 1 << "-й элемент массива: ";
        std::cin >> z[i];
        if ((z[i] >= -8) && (z[i] <= 3))
            m++;
    }

    form_new_arr(m, n, z);

    return 0;
}