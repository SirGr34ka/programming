#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
#include "hash_summ.h"

int main( int , char** )
{
    std::string image_path = "../kiwi.jpg";
    // Чтение изображения
    cv::Mat image = cv::imread( image_path );

    // Вывод оригинального изображения
    imshow( "original Image" , image );
    cv::waitKey(0);

    std::string original_image_hash = getHashSumm( image_path );

    // Изменение пикселя в изображении
    changePixel( image );

    // Вывод измененного изображения
    imshow( "changed Image" , image );
    cv::waitKey(0);

    std::string changed_image_hash = getHashSumm( image_path );
    
    std::cout << "Original image hash summary: " << original_image_hash << std::endl;
    std::cout << "Changed image hash summary: " << changed_image_hash << std::endl;
    std::cout << "Are equal: " << ( original_image_hash == changed_image_hash ) << std::endl;
     
    cv::destroyAllWindows();

    return 0;
}