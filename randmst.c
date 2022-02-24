#include "prim.h"
#include "time.h"

//#define nArray = [128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144]
// Capped at 512, 1024 doesn't work
int main(int argc, char* argv[])
{
    double time_spent = 0.0;
    clock_t begin = clock();
    int nArray[] = {128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144};
    // sets random seed for rand functionality
    srand( time(NULL) );
    if (argc != 5)
    {
        printf("Usage: ./randmst 0 numpoints numtrials dimension");
        return 1;
    }
    int numpoints = atoi(argv[2]);
    int numtrials = atoi(argv[3]);
    int dimension = atoi(argv[4]);
    if (numtrials < 0)
    {
        printf("Need positive number of trials");
        return 1;
    }
    node* list = graphVertices(numpoints, dimension);
    //print_nodes(list, numpoints, dimension);
    if (list == NULL)
    {
        printf("Graph Generation error");
        return 1;
    }
    float average = 0.0;
    for (int i = 0; i < numtrials; i++)
    {
        node* list = graphVertices(numpoints, dimension);
        if (list == NULL)
        {
            printf("Graph Generation error");
            return 1;
        }
        //print_nodes(list, numpoints, dimension);
        float result = prim(list, numpoints, dimension, i);
        printf("%f\n", result);
        //printf("Result %i (%i, dim: %i): %f \n", i, numpoints, dimension, result);
        average += result;
        fflush(stdout);
        clearNodes(list, numpoints);
    }
    average = average / numtrials;
    printf("Average: %f (%i, dim: %i, trials: %i)", average, numpoints, dimension, numtrials);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("The elapsed time is %f seconds", time_spent);
    return 0;
} 