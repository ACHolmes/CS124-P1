#include <stdio.h>
#include <stdlib.h>


#define nArray = [128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144]

typedef struct node{
    int x;
    int y;
    int z;
    int w;
} node;

typedef struct edge{
    float weight;
    node* from;
    node* to;
} edge;

int example();

node* generateNodesStatic(int n, int dim);
node* generateNodesHeap(int n, int dim);
edge* generateEdgesStatic(node* list, int n);

int main(int argc, char* argv[])
{
    if (argc != 5)
    {
        printf("Usage: ./randmst 0 numpoints numtrials dimension");
        return 1;
    }
    return 0;
}

int example()
{
    return 1;
}

node* generateNodesStatic(int n, int dim)
{
    node list[n];
    float temp[4] = {0};
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < dim; j++)
        {
            temp[i] = (float)rand()/RAND_MAX;
        }
        list[i].x = temp[0];
        list[i].y = temp[1];
        list[i].z = temp[2];
        list[i].w = temp[3];
    }
    return list;
}

edge* generateEdgesStatic(node* list, int n)
{
    return NULL;
}

node* generateNodesHeap(int n, int dim)
{
    node* start = malloc(n * sizeof(node));
    // is this a smart way of doing things?
    if(start == NULL)
    {
        return NULL;
    }
    node* cursor = start;
    for(int i = 0; i < n; i++){
        //logic needed here
        cursor += sizeof(node);
    }

}