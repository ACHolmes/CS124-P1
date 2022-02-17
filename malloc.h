#include "weight.h"

float *createBlank(int n, int dim)
{
    float *mat = calloc(n * n, sizeof(node));
    return mat;
}

void clearMat(float *mat, int n)
{
    free(mat);
}
