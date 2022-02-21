#include "r.h"
#include "struct.h"
#include <math.h>


void print_nodes(node* head, int n, int dim) {
    switch(dim)
    {
        case 1:
            for (int i = 0; i < n; i++) 
            {
                printf("%i: %f\n", head->n, head->x);
                fflush(stdout);
                head = head->next;
            }
            printf("%i: %f\n", head->n, head->x);
            return;
        case 2:
            for (int i = 0; i < n; i++) 
            {
                printf("%i: %f %f\n", head->n, head->x, head->y);
                fflush(stdout);
                head = head->next;
            }
            return;
        case 3:
            for (int i = 0; i < n; i++)
            {
                printf("%i: %f %f %f\n", head->n, head->x, head->y, head->z);
                fflush(stdout);
                head = head->next;
            }
            printf("%i: %f %f %f\n", head->n, head->x, head->y, head->z);
            return;
        case 4:
            for (int i = 0; i < n; i++)
            {
                printf("%i: %f %f %f %f\n", head->n, head->x, head->y, head->z, head->w);
                fflush(stdout);
                head = head->next;
            }
            printf("%i: %f %f %f %f\n", head->n, head->x, head->y, head->z, head->w);
            return;
    }
    printf("Invalid dimesion\n");
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

node* graphVertices(int n, int dim)
{
    node* head = malloc(sizeof(node));
    node* cursor = head;
    node* temp;
    node* out;
    int counter = 0;
    switch(dim)
    {
        case 1:
            for (int i = 0; i < n; i++)
            {
                node* newnode = malloc(sizeof(node));
                if(newnode == NULL)
                {
                    printf("Memory allocation error\n");
                    free(newnode);
                    clearNodes(head);
                    return NULL;
                }
                newnode->n = i;
                newnode->x = rand01();
                cursor->next = newnode;
                cursor = newnode;
            }
            out = head->next;
            free(head);
            return out;
        case 2:
            for (int i = 0; i < n; i++)
            {
                node* newnode = malloc(sizeof(node));
                if(newnode == NULL)
                {
                    free(newnode);
                    clearNodes(head);
                    printf("Node allocation error\n");
                    return NULL;
                }   
                cursor->next = newnode;
                newnode->x = rand01();
                newnode->y = rand01();
                newnode->n = i;
                cursor = newnode;
            }
            out = head->next;
            free(head);
            return out;
        case 3:
            for (int i = 0; i < n; i++)
            {
                node* newnode = malloc(sizeof(node));
                if(newnode == NULL)
                {
                    free(newnode);
                    clearNodes(head);
                    printf("Memory allocation error\n");
                    return NULL;
                }
                newnode->n = i;
                newnode->x = rand01();
                newnode->y = rand01();
                newnode->z = rand01();
                cursor->next = newnode;
                cursor = newnode;
            }
            out = head->next;
            free(head);
            return out;
        case 4:
            for (int i = 0; i < n; i++)
            {
                node* newnode = malloc(sizeof(node));
                if(newnode == NULL)
                {
                    printf("Memory allocation error\n");
                    return NULL;
                }
                newnode->n = i;
                newnode->x = rand01();
                newnode->y = rand01();
                newnode->z = rand01();
                newnode->w = rand01();
                cursor->next = newnode;
                cursor = newnode;
            }
            out = head->next;
            free(head);
            return head;
    }
    printf("Invalid dimension");
    return NULL;
}