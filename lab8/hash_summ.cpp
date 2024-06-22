#include <fstream>
#include <openssl/sha.h>
#include <stdint.h>
#include <sstream>

#include "hash_summ.h"

std::string getHashSumm( const std::string& file_path )
{
    std::stringstream result;

    unsigned char hash[ SHA256_DIGEST_LENGTH ];

    std::ifstream file( file_path , std::ios_base::in | std::ios_base::binary );

    file.seekg( 0 , std::ios::end );
    int size_of_buffer = file.tellg();
    file.seekg( 0 , std::ios::beg );

    char* data = new char [ size_of_buffer ];
    file.read( data , size_of_buffer );

    SHA256_CTX img;
    SHA256_Init( &img );
    SHA256_Update( &img , data , size_of_buffer );
    SHA256_Final( hash , &img );

    delete[] data;
   
    file.close();

    for ( int i = 0 ; i < SHA256_DIGEST_LENGTH ; ++i )
    {
        result << std::hex << ( int )hash[i];
    }

    return result.str();
}

void changePixel( cv::Mat &image )
{
    image.at< cv::Vec3b >( 50 , 50 )[0] = 0;

    return;
}