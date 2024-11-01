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

                while( ip_pool[j][0] != "46" || ip_pool[j][1] != "70" )
                {
                    --j;
                }

                return std::make_pair( i , ++j ) ;
            }
            ( 0 , ip_pool.size() - 1 );
    
        ip_pool_46_70.assign( std::next( ip_pool.cbegin() , std::get<0>( begin_end_iters ) ) , std::next( ip_pool.cbegin() , std::get<1>( begin_end_iters ) ) );

        print_ip_pool( ip_pool_46_70 );

        // ip = filter(46, 70)

        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76

        // TODO filter by any byte and output
        // ip = filter_any(46)

        // 186.204.34.46
        // 186.46.222.194
        // 185.46.87.231
        // 185.46.86.132
        // 185.46.86.131
        // 185.46.86.131
        // 185.46.86.22
        // 185.46.85.204
        // 185.46.85.78
        // 68.46.218.208
        // 46.251.197.23
        // 46.223.254.56
        // 46.223.254.56
        // 46.182.19.219
        // 46.161.63.66
        // 46.161.61.51
        // 46.161.60.92
        // 46.161.60.35
        // 46.161.58.202
        // 46.161.56.241
        // 46.161.56.203
        // 46.161.56.174
        // 46.161.56.106
        // 46.161.56.106
        // 46.101.163.119
        // 46.101.127.145
        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76
        // 46.55.46.98
        // 46.49.43.85
        // 39.46.86.85
        // 5.189.203.46
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
