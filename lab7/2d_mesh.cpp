#include "2d_mesh.h"

size_t greatest_common_divisor( size_t first_num , size_t second_num )
{
    if ( !( first_num % second_num ) )
    {
        return second_num;
    }

    if ( !( second_num % first_num ) )
    {
        return first_num;
    }

    if ( first_num > second_num )
    {
        return greatest_common_divisor( first_num / second_num , second_num );
    }
    else
    {
        return greatest_common_divisor( first_num , second_num / first_num );
    }
}

bool is_power_of_two( size_t num )
{
    return ( num && !( num & ( num - 1 ) ) );
}

bool is_it_possible_to_get( size_t fx , size_t fy )
{
    if ( is_power_of_two( fx ) || is_power_of_two( fy ) )
    {
        return true;
    }

    if ( fx == 0 || fy == 0 )
    {
        return false;
    }

    size_t gcd = greatest_common_divisor( fx , fy );

    if ( is_power_of_two( gcd ) )
    {
        return true;
    }

    return false;
}