#pragma once

#include "matrix.h"

class MaxPooling : public Matrix
{
    size_t stride;
    Matrix* input_matrix_ptr;
    Matrix* temp_matrix_ptr;

    public:

    // Конструктор
    MaxPooling(Matrix*& input_matrix, Matrix*& temp_matrix);

    Matrix getFeatureMap();
};