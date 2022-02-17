#include "r.h"
#include "struct.h"
#include <math.h>

int N;
// Takes in number of vertices, dimension and an empty matrix of the correct size
// And then actually outputs the adjacency matrix with the correct weights everywhere
void setN(int n){
    N = n;
}

float** graphWeights(int n, int dim, float** mat)
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
                    mat[i][j] = mat[j][i] = r;
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
                    float w = sqrt(( ( pow(nodes[i].x, 2) - pow(nodes[j].x, 2) ) + ( pow(nodes[i].y, 2) - pow(nodes[j].y, 2) ) ));
                    mat[i][j] = mat[j][i] = w;
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
                    float w = sqrt(( ( pow(nodes[i].x, 2) - pow(nodes[j].x, 2) ) + ( pow(nodes[i].y, 2) - pow(nodes[j].y, 2) ) 
                                   + ( pow(nodes[i].z, 2) - pow(nodes[j].z, 2) ) ));
                    mat[i][j] = mat[j][i] = w;
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
                    float w = sqrt(( ( pow(nodes[i].x, 2) - pow(nodes[j].x, 2) ) + ( pow(nodes[i].y, 2) - pow(nodes[j].y, 2) ) 
                                   + ( pow(nodes[i].z, 2) - pow(nodes[j].z, 2) ) + ( pow(nodes[i].z, 2) - pow(nodes[j].z, 2) ) ));
                    mat[i][j] = mat[j][i] = w;
                }
            }
            return mat;
    }
    return mat;
}

void printMat(float** mat, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%f ", mat[i][j]);
        }
        printf("%n");
    }
    return;
}