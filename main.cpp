#include <fstream>
#include <iostream>

#include "ip_filter.h"

int main(int, char **)
{
    try
    {
        // Передача из файла IP адресов
        std::ifstream file( "../../ip_filter.tsv" );

        std::vector<std::vector<std::string> > ip_pool;

        if ( file.is_open() )
        {
            std::string line;

            while( std::getline( file , line ) )
            {
                std::vector<std::string> v = split(line, '\t');
                ip_pool.push_back(split(v.at(0), '.'));
            }
        }

        file.close();

        // Вывод списков IP адресов
        print_sorted_ip_pool( ip_pool );
        print_ip_pool_1( ip_pool );
        print_ip_pool_46_70( ip_pool );
        print_ip_pool_any_46( ip_pool );
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}