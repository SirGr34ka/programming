#pragma once

#include <iostream>

/**
 * @brief
 * Определяет, можно ли добраться из начальной точки (1;1) в конечную точку (fx;fy),
 * если ходить можно только (x, y-x), (x-y, y), (2*x, y), (x, 2*y).
 * 
 * @param fx
 * x координата конечной точки
 * 
 * @param fy
 * y координата конечной точки
 * 
 * @return
 * Возвращает true, если можно попасть в конечную точку, иначе false.
 */
bool is_it_possible_to_get( size_t fx , size_t fy );