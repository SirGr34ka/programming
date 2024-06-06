#pragma once

/**
 * @brief
 * Поиск индекса человека со шваброй
 * 
 * @param n
 * число человек в шеренге
 * 
 * @param time
 * время, за которое передается швабра по шеренге
 * 
 * @return
 * Возвращает индекс человека со шваброй после окончания времени
 */
size_t who_is_going_to_clean_the_room(const int n, const int time);