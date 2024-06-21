#pragma once

#include <iostream>
#include <vector>
#include <string>

class HashTable
{
    size_t size = 10;
    size_t hash_value = ( size_t )( size * 1.5 );
    size_t* prices;
    size_t capacity = 0;

    public:

    /**
     * @brief
     * Конструктор по умолчанию (объект рассчитан на 10 позиций)
     */
    HashTable();

    /**
     * @brief
     * Конструктор (объект рассчитан на size позиций)
     * 
     * @param size
     * количество позиций
     */
    HashTable( const size_t size );

    /**
     * @brief
     * Преобразование строки в хэш
     * 
     * @param str
     * строка, хэш который нужно получить
     * 
     * @return
     * Возвращает хэш строки.
     */
    size_t getHash( const std::string& str ) const;

    /**
     * @brief
     * Добавление цены товара
     * 
     * @param product
     * наименование товара в виде строки
     * 
     * @param price
     * цена товара
     */
    void pushPrice( const std::string& product , const size_t price );

    /**
     * @brief
     * Удаление цены товара
     * 
     * @param product
     * наименование товара в виде строки
     */
    void popPrice( const std::string& product );

    /**
     * @brief
     * Поиск цены товара
     * 
     * @param product
     * наименование товара в виде строки
     * 
     * @return
     * Возвращает цену товара.
     */
    size_t searchPrice( const std::string& product ) const;

    /**
     * @brief
     * Проверка на пустую таблицу
     * 
     * @return
     * Возвращает true, если таблица пуста, иначе false
     */
    bool isEmpty() const;

    /**
     * @brief
     * Получает размер таблицы
     * 
     * @return
     * Возвращает размер таблицы
     */
    size_t getCapacity() const;

    /**
     * @brief
     * Деструктор
     */
    ~HashTable();
};