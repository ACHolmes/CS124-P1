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

void clearNodes(node* head)
{
    node* cursor = head;
    while (cursor != NULL)
    {
        node* temp = cursor->next;
        free(cursor);
        cursor = temp;
    }
    return;
}

edge* graphWeights(int n, int dim)
{
    edge* head = malloc(sizeof(edge));
    edge* cursor = head;
    node* nhead = malloc(sizeof(node));
    node* ncursor = nhead;
    int counter = 0;
    //float lim = (float) (100 * dim) / n;
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
                        printf("Edge allocation error");
                        clearWeights(head);
                        return NULL;
                    }
                    cursor->next = e;
                    e->weight = r;
                    e->from = i;
                    e->to = j;
                    cursor = e;
                }
            }
            edge* out1 = head->next;
            free(head);
            return out1;
        case 2:
            // Generating n with random x,y locations, in a linked list
            for (int i = 0; i < n; i++)
            {
                node* n = malloc(sizeof(node));
                if(n == NULL)
                {
                    printf("Node allocation error");
                    clearNodes(nhead);
                    return NULL;
                }   
                ncursor->next = n;
                n->x = rand01();
                n->y = rand01();
                n->n = counter;
                counter++;
                ncursor = n;
            }
            node* nodesi = nhead->next;
            node* nodesj = nodesi->next;
            free(nhead);
            print_nodes(nodesi);
            // Creating all edges between those nodes that we need
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    float w = sqrt(( ( pow(nodesi->x - nodesj->x, 2) ) + ( pow(nodesi->y  - nodesj->y, 2) ) ));
                    if (w > 1.1)
                    {
                        continue;
                    }
                    edge* e = malloc(sizeof(edge));
                    if (e == NULL){
                        printf("%i, %i \n", i, j);
                        printf("Edge allocation error");
                        clearWeights(head);
                        return NULL;
                    }
                    cursor->next = e;
                    e->weight = w;
                    e->from = i;
                    e->to = j;
                    printf("%i", e->to);
                    cursor = e;
                    printf("%i", cursor->to);
                    //printf("%i->%i, w: %f \n", e->from, e->to, e->weight);
                    nodesj = nodesj->next;
                }
                nodesi = nodesi->next;
                nodesj = nodesi->next;
            }
            edge* out2 = head->next;
            printf("\n %i", out2->from);
            free(head);
            print_edges(out2);
            return out2;
        /*case 3:
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