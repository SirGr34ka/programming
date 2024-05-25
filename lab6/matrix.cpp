#include <iostream>
#include "matrix.h"

Matrix::Matrix()
{
    rows = 2;
    columns = 2;

    matrix = new int* [rows];
        
    for (size_t i = 0; i < rows; ++i)
    {
        matrix[i] = new int [columns]{};
    }
}

Matrix::Matrix(const int& m, const int& n)
{
    rows = m;
    columns = n;

    matrix = new int* [rows];
        
    for (size_t i = 0; i < rows; ++i)
    {
        matrix[i] = new int [columns]{};
    }
}

Matrix::Matrix(Matrix& copied_matrix)
{
    rows = copied_matrix.getRows();
    columns = copied_matrix.getColumns();

    matrix = new int* [rows];
        
    for (size_t i = 0; i < rows; ++i)
    {
        matrix[i] = new int [columns];
    }

    *this = copied_matrix;
}

int** Matrix::getMatrix()
{
    return matrix;
}

int Matrix::getRows()
{
    return rows;
}

int Matrix::getColumns()
{
    return columns;
}

Matrix& Matrix::operator = (Matrix& right_matrix)
{
    const size_t m = rows;
    const size_t n = columns;
    int** right_matrix_ptr = right_matrix.getMatrix();

    for (size_t i = 0; i < m; ++i)
    {
        int* left_row = matrix[i];
        int* right_row = right_matrix_ptr[i];

        for (size_t j = 0; j < n; ++j)
        {
            left_row[j] = right_row[j];
        }
    }

    return *this;
}

Matrix Matrix::operator + (Matrix& right_matrix)
{
    const int m = rows;
    const int n = columns;
    int** right_matrix_ptr = right_matrix.getMatrix();

    Matrix result_matrix = *this;
    int** result_matrix_ptr = result_matrix.getMatrix();

    for (size_t i = 0; i < m; ++i)
    {
        int* right_row = right_matrix_ptr[i];
        int* result_row = result_matrix_ptr[i];

        for (size_t j = 0; j < n; ++j)
        {
            result_row[j] += right_row[j];
        }
    }

    return result_matrix;
}

Matrix::~Matrix()
{
    for (size_t i = 0; i < rows; ++i)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
}

std::ostream& operator << (std::ostream &os, Matrix& matrix)
{
    const size_t m = matrix.getRows();
    const size_t n = matrix.getColumns();
    int** matrix_ptr = matrix.getMatrix();

    for (size_t i = 0; i < m; ++i)
    {
        int* row = matrix_ptr[i];

        for (size_t j = 0; j < n; ++j)
        {
            os << row[j] << " ";
        }

        os << std::endl;
    }

    return os;
}

std::istream& operator >> (std::istream &is, Matrix& matrix)
{
    const size_t m = matrix.getRows();
    const size_t n = matrix.getColumns();
    int** matrix_ptr = matrix.getMatrix();

    for (size_t i = 0; i < m; ++i)
    {
        int* row = matrix_ptr[i];

        for (size_t j = 0; j < n; ++j)
        {
            is >> row[j];
        }
    }

    return is;
}