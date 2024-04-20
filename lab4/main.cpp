#include <opencv2/opencv.hpp>
#include <iostream>
 
int main()
{
    // Чтение изображения
    cv::Mat img = cv::imread("car.jpg"); // test.jpg или car.jpg

    // Вывод оригинального изображения
    imshow("original Image", img);
    cv::waitKey(0);
 
    // Конвертация изображения в серую палитру
    cv::Mat img_gray;
    cvtColor(img, img_gray, cv::COLOR_BGR2GRAY);

    // Размытие изображения, для уменьшения шума и улучшения работы выделения границ
    cv::Mat img_blur;
    GaussianBlur(img_gray, img_blur, cv::Size(3, 3), 0);
     
    // Sobel edge detection
    cv::Mat sobelxy;
    Sobel(img_blur, sobelxy, CV_8U, 1, 1, 5);

    // Вывод изображения после Sobel edge detection
    imshow("Sobel XY using Sobel() function", sobelxy);
    cv::waitKey(0);
 
    // Canny edge detection
    cv::Mat edges;
    Canny(img_blur, edges, 100, 200, 3, false);

    // Вывод изображения после Canny edge detection
    imshow("Canny edge detection", edges);
    cv::waitKey(0);
     
    cv::destroyAllWindows();

    return 0;
}