#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
#include <fstream>

#include "hash_summ.h"

int main( int , char** )
{
    std::string file_path = "../hash.txt";

    // Чтение изображения
    cv::Mat image = cv::imread( "../kiwi.jpg" );

    // Вывод оригинального изображения
    imshow( "original Image" , image );
    cv::waitKey(0);

    std::string original_image_hash = getHashSumm( "../kiwi.jpg" );

    // Изменение пикселя в изображении
    changePixel( image );

    cv::imwrite("../kiwi2.jpg", image );

    // Вывод измененного изображения
    imshow( "changed Image" , image );
    cv::waitKey(0);

    std::string changed_image_hash = getHashSumm( "../kiwi2.jpg" );

    std::cout << "Original image hash summary: " << original_image_hash << std::endl;
    std::cout << "Changed image hash summary: " << changed_image_hash << std::endl;
    std::cout << "Are equal: " << ( original_image_hash == changed_image_hash ) << std::endl;

    // Запись в файл hash.txt
    std::ofstream file( file_path );
    
    if ( file.is_open() )
    {
        file << "Original image hash summary: " << original_image_hash << "\n";
        file << "Changed image hash summary: " << changed_image_hash << "\n";
        file << "Are equal: " << ( original_image_hash == changed_image_hash ) << "\n";
    }

    file.close();
     
    cv::destroyAllWindows();

    return 0;
}