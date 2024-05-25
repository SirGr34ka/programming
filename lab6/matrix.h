#pragma once

#include <iostream>

class Matrix
{
    size_t rows;
    size_t columns;
    int** matrix;

    public:

    // Конструкторы
    Matrix();
    Matrix(const int& m, const int& n);

    // Конструктор копирования
    Matrix(Matrix& copied_matrix);

    // Гетеры
    int** getMatrix();
    int getRows();
    int getColumns();

    // Перегрузка операторов
    Matrix& operator = (Matrix& right_matrix);
    Matrix operator + (Matrix& right_matrix);

    // Деструктор
    ~Matrix();
};

// Переопределение операторов вывода
std::ostream& operator << (std::ostream& os, Matrix& matrix);
std::istream& operator >> (std::istream& is, Matrix& matrix);