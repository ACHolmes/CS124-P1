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


int main(void)
{
    //caps out at 8192
    int n = 16384;
    float* mat = createBlank(n, 2);
    mat = graphWeights(n, 2, mat);
    printMat(mat, n);
}