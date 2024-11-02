#include <cassert>
#include <cstdlib>

#include <iostream>

#include <string>
#include <vector>
#include <tuple>

#include <algorithm>

#include "ip_filter.h"

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

    while( stop != std::string::npos )
    {
        r.push_back( str.substr( start, stop - start ) );

        start = stop + 1;
        stop = str.find_first_of( d, start );
    }

    r.push_back( str.substr( start ) );

    return r;
}

void print_ip_pool( std::vector< std::vector< std::string > >& ip_pool )
{
    for( auto ip = ip_pool.cbegin() ; ip != ip_pool.cend() ; ++ip )
    {
        for( auto ip_part = ip->cbegin() ; ip_part != ip->cend() ; ++ip_part )
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

void print_sorted_ip_pool( std::vector< std::vector< std::string > >& ip_pool )
{
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

        return;
}

void print_ip_pool_1( std::vector< std::vector< std::string > > ip_pool )
{
    decltype( ip_pool ) ip_pool_1;

    ip_pool_1.assign(
        std::next( ip_pool.cbegin() ,[ & ]( size_t i ){ while( ip_pool[i++][0] != "1" ); return --i; }( 0 ) ),
        ip_pool.cend() );

    print_ip_pool( ip_pool_1 );

    return;
}

void print_ip_pool_46_70( std::vector< std::vector< std::string > > ip_pool )
{
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

    return;
}

void print_ip_pool_any_46( std::vector< std::vector< std::string > > ip_pool )
{
    decltype( ip_pool ) ip_pool_any_46 = [ & ]()
    {
        decltype( ip_pool ) ip_pool_temp;

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

    return;
}