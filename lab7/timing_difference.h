#pragma once

#include <iostream>
#include <vector>
#include <string>

/**
 * @brief
 * Поиск минимальной разницы между элементами вектора, которые имеют вид "ЧЧ:ММ"
 * 
 * @param timings
 * вектор со строками
 * 
 * @return 
 * Возвращает минимальную разницу между элементами
*/
int minDifference( std::vector< std::string >& timings );