#include "max_pooling.h"

MaxPooling::MaxPooling(Matrix*& input_matrix, Matrix*& temp_matrix) : Matrix(input_matrix->getRows() - temp_matrix->getRows() + 1, input_matrix->getColumns() - temp_matrix->getColumns() + 1)
{
    stride = 1;
    input_matrix_ptr = input_matrix;
    temp_matrix_ptr = temp_matrix;
}

Matrix MaxPooling::getFeatureMap()
{
    const size_t m = rows;
    const size_t n = columns;

    for (size_t i = 0; i < m; ++i)
    {
        int* row = matrix[i];

        for (size_t j = 0; j < n; ++j)
        {
            Matrix temp_matrix = temp_matrix_ptr->getPatch(*input_matrix_ptr, i, j);
            row[j] = temp_matrix.max();
        }
    }

    return *this;
}