#include <iostream>
#include <vector>
#include <string>

/**
 * @brief
 * Функция считает минимальное время, за которое будут доставлены все грузы
 * 
 * @param orders
 * заказы
 * 
 * @param time
 * время
 * 
 * @param transport
 * выбранный транспорт для доставки заказов (не выбран по умолчанию)
 * 
 * @return Возвращает минимальное время
*/
unsigned int min_time(const std::vector<std::string> &orders, const std::vector<unsigned int> &time, const std::string &transport = "")
{
    unsigned int res = 0;

    // Вычисление суммарного времени для трех грузовиков
    if (transport == "")
    {
        res = min_time(orders, time, "Е") + min_time(orders, time, "Э") + min_time(orders, time, "К");
    }
    else
    {
        std::vector<size_t> the_num_of_orders(orders.size());
        size_t cnt = 0, index = 0;

        for (size_t i = 0; i < orders.size(); ++i)
        {
            for (size_t j = 0; j < orders[i].size(); ++j)
            {
                if (orders[i][j] == transport[0])
                {
                    ++cnt;
                }
            }

            if (cnt > 0)
            {
                index = i;
            }

            the_num_of_orders[i] = cnt;
        }

        the_num_of_orders.resize(index + 1);
    }

    return res;
}

int main(int, char**)
{
    /**Заказы в i-ых домах, где: Е - Еда, Э - Электроника, К - Книги*/
    std::vector<std::string> orders{"Е", "Э", "ЕЭ", "ЕЕ"};

    /**Время в минутах, обозначающее сколько ехать от i-го до i+1-го домов*/
    std::vector<unsigned int> time{2, 3, 4};

    unsigned int res = min_time(orders, time);

    return 0;
}