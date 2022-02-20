#include "r.h"
#include "struct.h"
#include <math.h>


// Attempting to implement adjacency list format to reduce memory usage.

//print nodes in graph: 2D
void print_nodes2(node2* head) {
    node2* current = head;

    while (current != NULL) {
        printf("%i: %f %f %f %f\n", current->n, current->x, current->y, current->z, current->w);
        fflush(stdout);
        current = current->next;
    }
}

//print nodes in graph: 3D
void print_nodes3(node3* head) {
    node3* current = head;

    while (current != NULL) {
        printf("%i: %f %f %f %f\n", current->n, current->x, current->y, current->z);
        fflush(stdout);
        current = current->next;
    }
}

//print nodes in graph: 4D
void print_nodes4(node4* head) {
    node4* current = head;

    while (current != NULL) {
        printf("%i: %f %f %f %f\n", current->n, current->x, current->y, current->z, current->w);
        fflush(stdout);
        current = current->next;
    }
}

//print edges
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

void clearNodes2(node2* head)
{
    node2* cursor = head;
    while (cursor != NULL)
    {
        node2* temp = cursor->next;
        free(cursor);
        cursor = temp;
    }
    return;
}

void clearNodes3(node3* head)
{
    node3* cursor = head;
    while (cursor != NULL)
    {
        node3* temp = cursor->next;
        free(cursor);
        cursor = temp;
    }
    return;
}

void clearNodes4(node4* head)
{
    node4* cursor = head;
    while (cursor != NULL)
    {
        node4* temp = cursor->next;
        free(cursor);
        cursor = temp;
    }
    return;
}

edge* graphWeights2(int n, int dim)
{
    edge* head = malloc(sizeof(edge));
    edge* cursor = head;
    node2* nhead = malloc(sizeof(node2));
    node2* ncursor = nhead;
    node2* nodesi;
    node2* nodesj;
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
                node2* n = malloc(sizeof(node2));
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
    }
} 

edge* graphWeights3(int n, int dim)
{
    edge* head = malloc(sizeof(edge));
    edge* cursor = head;
    node3* nhead = malloc(sizeof(node3));
    node3* ncursor = nhead;
    node3* nodesi;
    node3* nodesj;
    edge* out;
    int counter = 0;
    //float lim = (float) (100 * dim) / n;
    
    // Generating n with random x,y,z locations, in a linked list
    for (int i = 0; i < n; i++)
    {
        node3* n = malloc(sizeof(node3));
        if(n == NULL)
        {
            free(n);
            clearNodes3(nhead);
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
    print_nodes3(nodesi);
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
                clearWeights3(head);
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
} 


edge* graphWeights4(int n, int dim)
{
    edge* head = malloc(sizeof(edge));
    edge* cursor = head;
    node4* nhead = malloc(sizeof(node4));
    node4* ncursor = nhead;
    node4* nodesi;
    node4* nodesj;
    edge* out;
    int counter = 0;
    //float lim = (float) (100 * dim) / n;
    
    // Generating n with random x,y,z locations, in a linked list
    for (int i = 0; i < n; i++)
    {
        node4* n = malloc(sizeof(node4));
        if(n == NULL)
        {
            free(n);
            clearNodes4(nhead);
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
    print_nodes4(nodesi);
    // Creating all edges between those nodes that we need
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            //fix for 4
            float w = sqrt(( ( pow(nodesi->x - nodesj->x, 2) ) + ( pow(nodesi->y  - nodesj->y, 2) )
                            + ( pow(nodesi->z  - nodesj->z, 2) ) ));
            edge* e = malloc(sizeof(edge));
            if (e == NULL){
                free(e);
                clearWeights4(head);
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
} 
