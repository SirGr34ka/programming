#include "equation_solution.h"

std::string getSolution( const std::string& equation )
{
    int x_multiplier = 0, summary = 0, temp_num;
    std::string temp = "";
    bool equal_sign_flag = false;

    for ( char symbol: equation )
    {
        // Берет число со знаком перед x и прибавляет его к x_multiplier
        if ( symbol == 'x' )
        {
            if( temp.empty() || ( temp.size() == 1 && temp[0] == '+' ) )
            {
                temp_num = 1;
            }
            else if( temp.size() == 1 && temp[0] == '-' )
            {
                temp_num = -1;
            }
            else
            {
                temp_num = stoi(temp);
            }

            x_multiplier += !equal_sign_flag ? temp_num : -temp_num;
            temp = "";
        }
        else if ( isdigit( symbol ) )
        {
            temp += symbol;
        }
        // Берет число со знаком перед знаком сложения или вычитания и прибавляет его к summary
        else if ( symbol == '+' || symbol == '-' )
        {
            int temp_num = temp.empty() ? 0 : stoi( temp );
            summary += equal_sign_flag ? temp_num : -temp_num;
            temp = symbol;
        }
        else if ( symbol == '=' )
        {
            if( !temp.empty() )
            {
                int temp_num = stoi( temp );
                summary += -temp_num;
                temp = "";
            }

            equal_sign_flag = true;
        }
    }

    if( !temp.empty() )
    {
        int temp_num = stoi( temp );
        summary += temp_num;
    }

    if ( summary == 0 && x_multiplier == 0 )
    {
        return "Infinite";
    }
    else if ( summary != 0 && x_multiplier == 0 )
    {
        return "NO";
    }

    return "x=" + std::to_string( summary / x_multiplier );
}