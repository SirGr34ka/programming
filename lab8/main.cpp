#include <iostream>
#include <math.h>
#include <string>
#include <fstream>
#include <vector>

const size_t hash_value = 40;

size_t getHash(const std::string& str)
{
    size_t res = 0;

    for ( size_t i = 0 ; i < str.size() ; ++i )
    {
        res += ( ( str[i] -'a' + 1 ) * ( size_t )( pow( 26 , i ) ) ) % 100000;
        res %= hash_value;
    }

    return res;
}

void enrolled( const std::string& file_path , std::vector< size_t >& voters )
{
    std::ifstream students( file_path );
    std::string lastname;

    if ( students.is_open() )
    {
        while ( std::getline( students , lastname ) )
        {
            voters[ getHash( lastname ) ] += 1;
        }
    }

    students.close();

    return;
}

void unenrolled( const std::string& lastname , std::vector< size_t >& voters )
{
    if ( voters[ getHash( lastname ) ] > 1 )
    {

    }
    else
    {
        voters[ getHash( lastname ) ] += 1;
    }

    return;
}

int main( int , char** )
{
    std::vector< size_t > voters( hash_value );

    

    return 0;
}