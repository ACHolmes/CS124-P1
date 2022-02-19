#include "r.h"
#include "struct.h"
#include <math.h>


// Attempting to implement adjacency list format to reduce memory usage.

void print_nodes(node* head) {
    node* current = head;

    while (current != NULL) {
        printf("%i: %f %f %f %f\n", current->n, current->x, current->y, current->z, current->w);
        fflush(stdout);
        current = current->next;
    }
}

void print_edges(edge* head)
{
    edge* current = head;

    while (current != NULL) {
        printf("%i -> %i, w: %f\n", current->from, current->to, current->weight);
        fflush(stdout);
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
    node* nodesi;
    node* nodesj;
    edge* out;
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
                    if (r > 1.2)
                    {
                        continue;
                    }
                    edge* e = malloc(sizeof(edge));
                    if (e == NULL){
                        clearWeights(head);
                        free(e);
                        printf("Edge allocation error");
                        return NULL;
                    }
                    cursor->next = e;
                    e->weight = r;
                    e->from = i;
                    e->to = j;
                    cursor = e;
                }
            }
            out = head->next;
            free(head);
            return out;
        case 2:
            // Generating n with random x,y locations, in a linked list
            for (int i = 0; i < n; i++)
            {
                node* n = malloc(sizeof(node));
                if(n == NULL)
                {
                    free(n);
                    clearNodes(nhead);
                    printf("Node allocation error");

                    return NULL;
                }   
                ncursor->next = n;
                n->x = rand01();
                n->y = rand01();
                n->n = counter;
                counter++;
                ncursor = n;
            }
            nodesi = nhead->next;
            nodesj = nodesi->next;
            free(nhead);
            print_nodes(nodesi);
            // Creating all edges between those nodes that we need
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    float w = sqrt(( ( pow(nodesi->x - nodesj->x, 2) ) + ( pow(nodesi->y  - nodesj->y, 2) ) ));
                    edge* e = malloc(sizeof(edge));
                    if (e == NULL){
                        free(e);
                        clearWeights(head);
                        printf("%i, %i \n", i, j);
                        printf("Edge allocation error");
                        return NULL;
                    }
                    cursor->next = e;
                    e->weight = w;
                    e->from = i;
                    e->to = j;
                    cursor = e;
                    nodesj = nodesj->next;
                }
                nodesi = nodesi->next;
                nodesj = nodesi->next;
                
            }
            out = head->next;
            free(head);
            return out;
        case 3:
            // Generating n with random x,y,z locations, in a linked list
            for (int i = 0; i < n; i++)
            {
                node* n = malloc(sizeof(node));
                if(n == NULL)
                {
                    free(n);
                    clearNodes(nhead);
                    printf("Node allocation error");
                    return NULL;
                }   
                ncursor->next = n;
                n->x = rand01();
                n->y = rand01();
                n->z = rand01();
                n->n = counter;
                counter++;
                ncursor = n;
            }
            nodesi = nhead->next;
            nodesj = nodesi->next;
            free(nhead);
            print_nodes(nodesi);
            // Creating all edges between those nodes that we need
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    float w = sqrt(( ( pow(nodesi->x - nodesj->x, 2) ) + ( pow(nodesi->y  - nodesj->y, 2) )
                                   + ( pow(nodesi->z  - nodesj->z, 2) ) ));
                    edge* e = malloc(sizeof(edge));
                    if (e == NULL){
                        free(e);
                        clearWeights(head);
                        printf("%i, %i \n", i, j);
                        printf("Edge allocation error");
                        return NULL;
                    }
                    cursor->next = e;
                    e->weight = w;
                    e->from = i;
                    e->to = j;
                    cursor = e;
                    nodesj = nodesj->next;
                }
                nodesi = nodesi->next;
                nodesj = nodesi->next;
                
            }
            out = head->next;
            free(head);
            return head;
        case 4:
            // Generating n with random x,y,z locations, in a linked list
            for (int i = 0; i < n; i++)
            {
                node* n = malloc(sizeof(node));
                if(n == NULL)
                {
                    free(n);
                    clearNodes(nhead);
                    printf("Node allocation error");
                    return NULL;
                }   
                ncursor->next = n;
                n->x = rand01();
                n->y = rand01();
                n->z = rand01();
                n->w = rand01();
                n->n = counter;
                counter++;
                ncursor = n;
            }
            nodesi = nhead->next;
            nodesj = nodesi->next;
            free(nhead);
            print_nodes(nodesi);
            // Creating all edges between those nodes that we need
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    float w = sqrt(( ( pow(nodesi->x - nodesj->x, 2) ) + ( pow(nodesi->y  - nodesj->y, 2) )
                                   + ( pow(nodesi->z - nodesj->z, 2) ) + ( pow(nodesi->w  - nodesj->w, 2) ) ));
                    edge* e = malloc(sizeof(edge));
                    if (e == NULL){
                        free(e);
                        clearWeights(head);
                        printf("%i, %i \n", i, j);
                        printf("Edge allocation error");
                        return NULL;
                    }
                    cursor->next = e;
                    e->weight = w;
                    e->from = i;
                    e->to = j;
                    cursor = e;
                    nodesj = nodesj->next;
                }
                nodesi = nodesi->next;
                nodesj = nodesi->next;
                
            }
            out = head->next;
            free(head);
            return out;
    }
}