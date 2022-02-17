#include "r.h"
#include "struct.h"
#include <math.h>

// Creates adjacency matrix with randomized weights
// of correct size and dimension, takes in empty n x n mat, fills it and returns
// pointer to head of mat.
float* graphWeights(int n, int dim, float* mat)
{
    node nodes[n];
    switch (dim)
    {
        case 1:
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    float r = rand01();
                    *(mat + i*n + j) = *(mat + j*n + i) = r;
                }
            }
            return mat;
        case 2:
            
            for (int i = 0; i < n; i++)
            {
                nodes[i].x = rand01();
                nodes[i].y = rand01();
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    float w = sqrt(( ( pow(nodes[i].x - nodes[j].x, 2) ) + ( pow(nodes[i].y  - nodes[j].y, 2) ) ));
                    *(mat + i*n + j) = *(mat + j*n + i) = w;
                }
            }
            return mat;
        case 3:
            for (int i = 0; i < n; i++)
            {
                nodes[i].x = rand01();
                nodes[i].y = rand01();
                nodes[i].z = rand01();
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    float w = sqrt(( ( pow(nodes[i].x - nodes[j].x, 2) ) + ( pow(nodes[i].y - nodes[j].y, 2) ) 
                                   + ( pow(nodes[i].z - nodes[j].z, 2) ) ));
                    *(mat + i*n + j) = *(mat + j*n + i) = w;
                }
            }
            return mat;
        case 4:
            for (int i = 0; i < n; i++)
            {
                nodes[i].x = rand01();
                nodes[i].y = rand01();
                nodes[i].z = rand01();
                nodes[i].w = rand01();
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    float w = sqrt(( ( pow(nodes[i].x - nodes[j].x, 2) ) + ( pow(nodes[i].y - nodes[j].y, 2) ) 
                                   + ( pow(nodes[i].z - nodes[j].z, 2) ) + ( pow(nodes[i].z - nodes[j].z, 2) ) ));
                    *(mat + i*n + j) = *(mat + j*n + i) = w;
                }
            }
            return mat;
    }
    return mat;
}

void printMat(float* mat, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%f ", *(mat + i*n + j));
        }
        printf("\n");
    }
    return;
}