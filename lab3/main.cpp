#include <iostream>
#include <vector>
#include <string>

/**
 * @brief
 * Считает время, за которое один транспорт доставляет грузы по домам
 * 
 * @param orders
 * заказы
 * 
 * @param time
 * время между домами
 * 
 * @param transport
 * выбранный транспорт для доставки заказов (не выбран по умолчанию)
 * 
 * @param res
 * полученное время
 * 
 * @return Время одного транспорта
*/
unsigned int time_costs(const std::vector<std::string> &orders, const std::vector<unsigned int> &time, const char &transport, unsigned int& res)
{
    std::vector<size_t> the_num_of_orders(orders.size());
    size_t cnt = 0, index = 0;

    // Вычисление кол-ва заказов по домам
    for (size_t i = 0; i < orders.size(); ++i)
    {
        for (size_t j = 0; j < orders[i].size(); ++j)
        {
            if (orders[i][j] == transport)
            {
                ++cnt;
            }
        }

        if (cnt > 0)
        {
            index = i + 1;
        }

        the_num_of_orders[i] = cnt;

        cnt = 0;
    }

    // Если дальше заказов нет, то уменьшаем кол-во домов
    the_num_of_orders.erase(the_num_of_orders.begin() + index, the_num_of_orders.end());

    // Разгрузка в первом доме
    res += the_num_of_orders[0];

    // Разгрузка + время до этого дома
    for (size_t i = 1; i < the_num_of_orders.size(); ++i)
    {
        res += time[i - 1] + the_num_of_orders[i];
    }

    return res;
}

/**
 * @brief
 * Считает минимальное время, за которое будут доставлены все грузы
 * 
 * @param orders
 * заказы
 * 
 * @param time
 * время между домами
 * 
 * @param transport
 * выбранный транспорт для доставки заказов (не выбран по умолчанию)
 * 
 * @return Минимальное время на доставку грузов
*/
unsigned int min_time(const std::vector<std::string> &orders, const std::vector<unsigned int> &time, const char &transport = ' ')
{
    unsigned int res = 0;

    if (!(orders.empty()) && !(time.empty()) && (orders.size() - 1 == time.size()))
    {
        if (transport == ' ')
        {
            res = min_time(orders, time, 'F') + min_time(orders, time, 'E') + min_time(orders, time, 'B'); // Вычисление суммарного времени для трех грузовиков
        }
        else
        {
            res = time_costs(orders, time, transport, res);
        }
    }
    
    return res;
}

int main(int, char**)
{
    /** Заказы в i-ых домах, где: F - Food,  E - Electronics, B - Books */
    const std::vector<std::string> orders{"F", "E", "FE", "FF"};

    /**Время в минутах, которое показывает сколько ехать от i-го до i+1-го домов*/
    const std::vector<unsigned int> time{2, 3, 4};

    unsigned int res = min_time(orders, time);

    return 0;
}