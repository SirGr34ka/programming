#pragma once

#include <cassert>
#include <cstdlib>

#include <string>
#include <vector>
#include <tuple>

#include <algorithm>

/**
 * @brief
 * Раздерение строки по заданному знаку
 * 
 * @param str
 * строка, которую нужно разделить
 * 
 * @param d
 * знак, по которому нужно разделить строку
 * 
 * @return
 * Возвращает вектор из разделенных элементов строки
 */
std::vector<std::string> split(const std::string &str, char d);

template< typename T >

/**
 * @brief
 * Вывод IP адресов
 * 
 * @param ip_pool
 * Список IP адресов
 */
void print_ip_pool( std::vector< std::vector< T > >& ip_pool );

/**
 * @brief
 * Вывод IP адресов отсортированных в обратном лексикографическом порядке
 * 
 * @param ip_pool
 * Список IP адресов
 */
void print_sorted_ip_pool( std::vector< std::vector< std::string > >& ip_pool );

/**
 * @brief
 * Вывод IP адресов, если первый байт является 1
 * 
 * @param ip_pool
 * Список IP адресов
 */
void print_ip_pool_1( std::vector< std::vector< std::string > > ip_pool );

/**
 * @brief
 * Вывод IP адресов, если первый байт является 46, а второй - 70
 * 
 * @param ip_pool
 * Список IP адресов
 */
void print_ip_pool_46_70( std::vector< std::vector< std::string > > ip_pool );

/**
 * @brief
 * Вывод IP адресов, если любой байт является 46
 * 
 * @param ip_pool
 * Список IP адресов
 */
void print_ip_pool_any_46( std::vector< std::vector< std::string > > ip_pool );