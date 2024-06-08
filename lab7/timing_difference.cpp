#include "timing_difference.h"

int minDifference( std::vector<std::string>& timings )
{
    // Проверка на пустой вектор
    if ( !timings.empty() == 0 )
    {
        return -1;
    }

    std::vector<size_t> timings_in_minutes( timings.size() );
    size_t min_difference, difference;

    for ( size_t i = 0; i < timings.size(); ++i )
    {   
        // Преобразование строк в минуты
        std::string timing = timings[i];
        size_t hours = std::stoull( timing.substr( 0, 2 ) ), minutes = std::stoull( timing.substr( 3, 2 ) );

        // Проверка на верный формат времени
        if ( hours > 23 || minutes > 59 )
        {
            return -1;
        }

        timings_in_minutes[i] = hours * 60 + minutes;

        // Вычисление первой разницы
        if ( i == 1 )
        {
            difference = abs( timings_in_minutes[0] - timings_in_minutes[1] );
            min_difference = difference;
        }
        else if ( i > 1 )
        {
            // Поиск минимальной разницы
            for ( size_t j = 0; j < i; ++j )
            {
                difference = abs( timings_in_minutes[i] - timings_in_minutes[j] );
                min_difference = min_difference < difference ? min_difference : difference;
            }
        }
    }

    return min_difference;
}