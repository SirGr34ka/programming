#pragma once

#include <iostream>

#include <memory>
#include <cmath>

template <typename T>
class SequenceContainer
{
    const float EXPANSION_COEFFICIENT = 1.5F;
    std::shared_ptr< T[] > container;
    size_t capacity_;
    size_t size_;

    public:

    /**
     * @brief
     * Конструктор класса
     */
    SequenceContainer()
    {
        capacity_ = 2;
        size_ = 0;

        // Умный указатель на контейнер
        container = std::make_shared< T[] >( capacity_ );
    }

    /**
     * @brief
     * Метод добавления элемента в конец
     * 
     * @param element
     * элемент, который нужно вставить
     */
    void push_back( T& element )
    {
        std::shared_ptr< T[] > temp;

        if ( capacity_ >= ( size_ + 1 ) )
        {
            container[ size_++ ] = element;
        }
        else
        {
            size_t new_capacity = (size_t)std::round( capacity_ * EXPANSION_COEFFICIENT );

            temp = std::make_shared< T[] >( new_capacity );

            for ( size_t i = 0 ; i < capacity_ ; ++i )
            {
                temp[i] = container[i];
            }

            container = temp;
            capacity_ = new_capacity;

            temp[ size_++ ] = element;
        }

        return;
    }

    /**
     * @brief
     * Метод вставки элемента в произвольную позицию
     * 
     * @param index
     * индекс, на который нужно вставить элемент
     * @param element
     * элемент, который нужно вставить
     */
    void insert( size_t index , T& element )
    {
        if( index > size_ )
        {
            throw "Out of size";
        }

        std::shared_ptr< T[] > temp;

        if ( capacity_ >= ( size_ + 1 ) )
        {
            if ( index == size_ )
            {
                container[ size_++ ] = element;

                return;
            }

            temp = std::make_shared< T[] >( capacity_ );

            for ( size_t i = 0 , j = 0 ; i < size_ ; ++i , ++j )
            {
                if ( i == index )
                {
                    temp[j++] = element;
                    ++size_;
                }

                temp[j] = container[i];
            }
        }
        else
        {
            size_t new_capacity = (size_t)std::round( capacity_ * EXPANSION_COEFFICIENT );

            capacity_ = new_capacity;

            if ( index == size_ )
            {
                container[ size_++ ] = element;

                return;
            }

            temp = std::make_shared< T[] >( new_capacity );

            for ( size_t i = 0 , j = 0 ; i < size_ ; ++i , ++j )
            {
                if ( i == index )
                {
                    temp[j++] = element;
                }

                temp[j] = container[i];
            }

            ++size_;

            container = temp;
        }

        return;
    }

    void erase( size_t index , size_t size_ = 1 )
    {
        if ( ( index + size_ ) > this.size_ )
        {
            throw "Out of size";
        }

        std::shared_ptr< T[] > temp;

        return;
    }
    
    /**
     * @brief
     * Получение текущего размера контейнера
     * 
     * @return
     * Возвращает текущий размер контейнера
     */
    auto capacity() const
    {
        return capacity_;
    }

    /**
     * @brief
     * Получение текущего количества элементов в контейнере
     * 
     * @return
     * Возвращает текущее количество элементов в контейнере
     */
    auto size() const
    {
        return size_;
    }

    /**
     * @brief
     * Переопределение оператора []
     * 
     * @param index
     * индекс элемента
     * 
     * @return
     * Возвращает элемент, находящийся под заданным индексом
     */
    auto operator [] ( size_t index )
    {
        return container[ index ];
    }

    /**
     * @brief
     * Деструктор класса
     */
    ~SequenceContainer()
    {
        
    }
};

class ListContainer
{
    public:

    ListContainer();
    void push_back();
    void insert();
    void erase();
    auto size();
    auto operator [] ( size_t index );
    ~ListContainer();
};