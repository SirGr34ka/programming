#include <cassert>
#include <cstdlib>

#include <fstream>
#include <iostream>

#include <string>
#include <vector>
#include <tuple>

#include <algorithm>

#include "lib.h"

// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]
std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

void print_ip_pool( std::vector< std::vector< std::string > >& ip_pool )
{
    for( auto ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
    {
        for( auto ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part )
        {
            if (ip_part != ip->cbegin())
            {
                std::cout << ".";
            }

            std::cout << *ip_part;
        }
        
        std::cout << std::endl;
    }
}

int main(int, char **)
{
    try
    {
        std::ifstream file( "../../ip_filter.tsv" );

        std::vector<std::vector<std::string> > ip_pool;

        std::string line;

        if ( file.is_open() )
        {
            while( std::getline( file , line ) )
            {
                std::vector<std::string> v = split(line, '\t');
                ip_pool.push_back(split(v.at(0), '.'));
            }
        }

        file.close();

        // TODO reverse lexicographically sort

        std::sort( ip_pool.begin() , ip_pool.end() ,
        []( auto a , auto b )
        {
            for ( auto i = 0 ; i < 4 ; ++i )
            {
                if ( std::stoi( a[i] ) > std::stoi( b[i] ) )
                {
                    return true;
                }
                else if ( a[i] != b[i] )
                {
                    return false;
                }
            }

            return false;
        }
        );

        print_ip_pool( ip_pool );

        // TODO filter by first byte and output

        decltype( ip_pool ) ip_pool_1;

        ip_pool_1.assign(
            std::next( ip_pool.cbegin() ,[ & ]( size_t i = 0 ){ while( ip_pool[i++][0] != "1" ); return --i; }() ),
            ip_pool.cend() );

        print_ip_pool( ip_pool_1 );

        // TODO filter by first and second bytes and output
        decltype( ip_pool ) ip_pool_46_70;
        auto begin_end_iters = [ & ]( size_t i , size_t j )
            {
                while( ip_pool[i++][0] != "46" || ip_pool[i][1] != "70" );

                while( ip_pool[--j][0] != "46" || ip_pool[j][1] != "70" );

                return std::make_pair( i , ++j );
            }
            ( 0 , ip_pool.size() );
    
        ip_pool_46_70.assign( std::next( ip_pool.cbegin() , std::get<0>( begin_end_iters ) ) , std::next( ip_pool.cbegin() , std::get<1>( begin_end_iters ) ) );

        print_ip_pool( ip_pool_46_70 );

        // TODO filter by any byte and output
        decltype( ip_pool ) ip_pool_any_46 = [ & ](  )
        {
            decltype( ip_pool ) ip_pool_temp{};

            for( auto ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
            {
                for( auto ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part )
                {
                    if ( *ip_part == "46" )
                    {
                        ip_pool_temp.push_back( *ip );
                        break;
                    }
                }
            }

            return ip_pool_temp;
        }();

        print_ip_pool( ip_pool_any_46 );
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
