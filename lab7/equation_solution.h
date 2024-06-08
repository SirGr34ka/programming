#pragma once

#include <string>

/**
 * @brief
 * Решает линейные уравнения, содержащие операции сложения и вычитания
 * 
 * @param equation
 * уравнение в виде строки
 * 
 * @return
 * Возвращает строку вида "x=int", где int целочисленное число.
 * Если решения нет, то возвращает "NO".
 * Если бесконечное множество решений, то возвращает "Infinite".
*/
std::string getSolution( const std::string& equation );