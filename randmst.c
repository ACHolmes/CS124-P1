#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <float.h>
#include "r.h"
#include "struct.h"
#include "math.h"

//#include "SMFT.h"
//#include "weight.h"

#define nArray = [128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144]

int main(int argc, char* argv[])
{
    srand( time(NULL));
    if (argc != 5)
    {
        printf("Usage: ./randmst 0 numpoints numtrials dimension");
        return 1;
    }
    int n = 3;
    float mat[3][3] = {{0, 0 , 0 }, {0, 0, 0}, {0, 0, 0}};
    node nodes[n];
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
                printf("%f", w);
                mat[i][j] = mat[j][i] = w;
            }
        }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%f a ", mat[i][j]);
        }
        printf("%n");
    }
}

