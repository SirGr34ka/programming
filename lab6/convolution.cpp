#include "convolution.h"

Convolution::Convolution(Matrix*& input_matrix, Matrix*& kernel) : Matrix(input_matrix->getRows() - kernel->getRows() + 1, input_matrix->getColumns() - kernel->getColumns() + 1)
{
    stride = 1;
    input_matrix_ptr = input_matrix;
    kernel_ptr = kernel;
}

Matrix Convolution::getFeatureMap()
{
    const size_t m = rows;
    const size_t n = columns;

    for (size_t i = 0; i < m; ++i)
    {
        int* row = matrix[i];

        for (size_t j = 0; j < n; ++j)
        {
            row[j] = dotProduct(*input_matrix_ptr, *kernel_ptr, i, j);
        }
    }

    return *this;
}