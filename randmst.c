#include "malloc.h"

#define nArray = [128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144]
// Capped at 512, 1024 doesn't work
int main(int argc, char* argv[])
{
    // sets random seed for rand functionality
    srand( time(NULL));
    if (argc != 5)
    {
        printf("Usage: ./randmst 0 numpoints numtrials dimension");
        return 1;
    }

    // Currently caps out at 8192 :( too much malloc!
    int n = 8192;
    float* mat = createBlank(n, 2);
    mat = graphWeights(n, 2, mat);
    printMat(mat, n);
}

