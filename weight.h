#include "r.h"
#include "struct.h"
#include <math.h>

// Attempting to implement adjacency list format to reduce memory usage.

void print_nodes(node* head) {
    node* current = head;

    while (current != NULL) {
        printf("%i: %f %f %f %f\n", current->n, current->x, current->y, current->z, current->w);
        current = current->next;
    }
}

void print_edges(edge* head)
{
    edge* current = head;

    while (current != NULL) {
        printf("%i -> %i, w: %f\n", current->from, current->to, current->weight);
        current = current->next;
    }
}

void clearWeights(edge* head)
{
    edge* cursor = head;
    while (cursor != NULL)
    {
        edge* temp = cursor->next;
        free(cursor);
        cursor = temp;
    }
    return;
}

edge* graphWeights(int n, int dim)
{
    edge* head = malloc(sizeof(node));
    edge* cursor = head;
    float lim = (float) (100 * dim) / n;
    switch (dim)
    {
        case 1:
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    float r = rand01();
                    if (r > 0.2)
                    {
                        continue;
                    }
                    edge* e = malloc(sizeof(edge));
                    if (e == NULL){
                        printf("%i, %i", i, j);
                        printf("Allocation error");
                        clearWeights(cursor);
                        return NULL;
                    }
                    cursor->next = e;
                    e->weight = r;
                    e->from = i;
                    cursor = e;
                }
            }
            edge* out = head->next;
            free(head);
            return out;
        /*case 2:
            node* head;
            node* cursor = head;
            for (int i = 0; i < n; i++)
            {
                
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    float r = rand01();
                    edge* e = malloc(sizeof(edge));
                    if (e == NULL){
                        printf("Allocation error");
                        clearWeights(cursor);
                        return NULL;
                    }
                    cursor->next = e;
                    cursor = e;
                    e->weight = r;
                    e->from = i;
                    e->to = j;
                    e->next = NULL;
                }
            }
            return head;
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
    */}
    //return mat;
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