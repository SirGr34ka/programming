#pragma once

#include <string>
#include <opencv2/opencv.hpp>

/**
 * @brief
 * Получение хэш-суммы изображения
 * 
 * @param file_path
 * путь к изображению
 * 
 * @return
 * Возвращает строку с хэш-суммой изображения.
*/
std::string getHashSumm( const std::string& file_path );

/**
 * @brief
 * Изменяет голубой цветовой канал на 0 пикселя (30; 30)
 * 
 * @param image
 * изображение
*/
void changePixel( cv::Mat &image );