#pragma once

#include <iostream>
#include <vector>
#include <string>

/**
 * @brief
 * Хэш-функция
 * 
 * @param str
 * строка, для которой нужно вычислить хэш
 * 
 * @return
 * Возвращает хэш входной строки
 */
size_t getHash( const std::string& str );

/**
 * @brief
 * Читает файл с фамилиями и отмечает их как проголосовавшие
 * 
 * @param file_path
 * путь до файла, в котором хранятся фамилии
 */
void enrolled( const std::string& file_path );

/**
 * @brief
 * Отмечает фамилию как проголосовавшую или делает пометку о дубликате
 * 
 * @param lastname
 * Фамилия в виде строки
 */
void unenrolled( const std::string& lastname );

/**
 * @brief
 * Вывод количества участников, дубликатов и фамилии участников
 */
void output();