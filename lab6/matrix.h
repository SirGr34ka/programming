#pragma once

#include <iostream>

class Matrix
{
    protected:
    
    size_t rows;
    size_t columns;
    int** matrix;

    public:

    /**
     * @brief
     * Конструктор класса по умолчанию
     * 
     * @param m
     * количество строк матрицы
     * 
     * @param n
     * количество столбцов матрицы
    */
    Matrix();

    /**
     * @brief
     * Конструктор класса
     * 
     * @param m
     * количество строк матрицы
     * 
     * @param n
     * количество столбцов матрицы
    */
    Matrix(const int& m, const int& n);

    /**
     * @brief
     * Конструктор копирования
     * 
     * @param copied_matrix
     * скоп
    */
    Matrix(Matrix& copied_matrix);

    // Гетеры
    int** getMatrix();
    const int** getMatrix() const;
    int getRows();
    int getColumns();

    // Поиск максимального значения
    int max();

    // Скалярное произведение матриц
    int dotProduct(Matrix& right_matrix, const size_t& row_offset, const size_t& column_offset);

    // Часть матрицы
    Matrix getPatch(Matrix& input_matrix, const size_t& row_offset, const size_t& column_offset);

    // Перегрузка операторов
    Matrix operator + (Matrix right_matrix);
    Matrix operator - (Matrix right_matrix);
    Matrix operator * (const int& right_num);
    Matrix operator * (const Matrix& right_matrix) const;
    Matrix& operator = (Matrix& right_matrix);
    bool operator == (Matrix& right_matrix);

    // Деструктор
    ~Matrix();
};

// Переопределение операторов вывода
std::ostream& operator << (std::ostream& os, Matrix& matrix);
std::istream& operator >> (std::istream& is, Matrix& matrix);