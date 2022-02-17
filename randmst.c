#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <float.h>
#include "r.h"
#include "weight.h"

#define nArray = [128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144]

int main(int argc, char* argv[])
{
    if (argc != 5)
    {
        printf("Usage: ./randmst 0 numpoints numtrials dimension");
        return 1;
    }
    float mat[3][3] = {{0, 0 , 0 }, {0, 0, 0}, {0, 0, 0}};
    printMat(graphWeights(3, 2, mat), 3);
}

/*
int example()
{
    return 1;
}

float* generateGraph(int n, int dim)
{
    float graph[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            float r = rand01();
            graph[i][j] = r;
            graph[j][i] = r;
        }
    }
    return graph;
} 

int minKey(int key[], bool mstSet[], int n)
{
    // Initialize min value
    int min = FLT_MAX, min_index;
 
    for (int v = 0; v < n; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
 
    return min_index;
}

int printMST(float parent[], int n, float graph[n][n])
{
    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int n, float graph[n][n])
{
	// Array to store constructed MST
	float parent[n];
	// Key values used to pick minimum weight edge in cut
	int key[n];
	// To represent set of vertices included in MST
	bool mstSet[n];

	// Initialize all keys as INFINITE
	for (int i = 0; i < n; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	// Always include first 1st vertex in MST.
	// Make key 0 so that this vertex is picked as first vertex.
	key[0] = 0;
	parent[0] = -1; // First node is always root of MST

	// The MST will have V vertices
	for (int count = 0; count < n - 1; count++) {
		// Pick the minimum key vertex from the
		// set of vertices not yet included in MST
		int u = minKey(key, mstSet, n);

		// Add the picked vertex to the MST Set
		mstSet[u] = true;

		// Update key value and parent index of
		// the adjacent vertices of the picked vertex.
		// Consider only those vertices which are not
		// yet included in MST
		for (int v = 0; v < n; v++)

			// graph[u][v] is non zero only for adjacent vertices of m
			// mstSet[v] is false for vertices not yet included in MST
			// Update the key only if graph[u][v] is smaller than key[v]
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}

	// print the constructed MST
	printMST(parent, graph, n);
}*/