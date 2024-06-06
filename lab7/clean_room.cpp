#include <iostream>

#include "clean_room.h"

size_t who_is_going_to_clean_the_room(const int n, const int time)
{
    if ( n <= 0 || time < 0 )
    {
        return 0;
    }

    size_t index = 0;
    bool flag = 0; // Флаг направления, 0 - справа налево, 1 - слева направо

    for ( size_t i = 0; i < time; ++i )
    {
        ++index;

        // Меняем направление
        if ( index >= n )
        {
            flag ^= 1;
            index = 1;
        }
    }

    if ( !flag )
    {
        return index + 1;
    }
    else
    {
        return n - index;
    }
}