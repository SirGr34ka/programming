#include <math.h>
#include <fstream>

#include "hash_table.h"

const size_t hash_value = 40;
size_t duplicates = 0;
size_t voters_count = 0;
std::vector< size_t > voters( hash_value );
std::string lastnames = "";

size_t getHash( const std::string& str )
{
    size_t hash = 0;

    for ( size_t i = 0 ; i < str.size() ; ++i )
    {
        hash += ( str[i] * ( size_t )( pow( log( i + 1488 ) , i ) ) ) % 100;
    }

    return hash % hash_value;
}

void enrolled( const std::string& file_path )
{
    std::ifstream file( file_path );
    std::string lastname;

    if ( file.is_open() )
    {
        while ( std::getline( file , lastname ) )
        {
            unenrolled( lastname );
        }
    }

    file.close();

    return;
}

void unenrolled( const std::string& lastname )
{
    size_t hash = getHash( lastname );
    voters[ hash ] += 1;
    
    if ( voters[ hash ] > 1 )
    {
        duplicates += 1;
    }
    else
    {
        voters_count += 1;
        lastnames += lastname + " ";
    }

    return;
}

void output()
{
    std::cout << "Number of voters: " << voters_count << std::endl;
    std::cout << "Duplicates: " << duplicates << std::endl;
    std::cout << "List of voters: " << lastnames << std::endl;

    return;
}