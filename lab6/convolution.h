#pragma once

#include "matrix.h"

class Convolution : public Matrix
{
    size_t stride;
    Matrix* input_matrix_ptr;
    Matrix* kernel_ptr;

    public:

    // Конструктор
    Convolution(Matrix*& input_matrix, Matrix*& kernel);

    Matrix getFeatureMap();
};