#pragma once

#include <stdint.h>

/**
 * @brief
 * Определяет, можно ли добраться из одной точки в другую за t шагов на двумерной сетке
 * 
 * @param sx
 * x координата начальной точки
 * 
 * @param sy
 * y координата начальной точки
 * 
 * @param fx
 * x координата конечной точки
 * 
 * @param fy
 * y координата начальной точки
 * 
 * @param t
 * количество шагов, за которое нужно дойти из начальной точки в конечную
 * 
 * @return
 * Возвращает true или false в зависимости от возможности дойти из одной точки в другую за t шагов
 */
bool is_it_possible_to_get(const int32_t sx, const int32_t sy, const int32_t fx, const int32_t fy, const uint32_t t);