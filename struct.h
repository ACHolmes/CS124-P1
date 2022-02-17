// Typedefs for structs
typedef struct node{
    float x;
    float y;
    float z;
    float w;
} node;

typedef struct edge{
    float weight;
    node* from;
    node* to;
} edge;

typedef struct graph{
    node* nodes;
    edge* edges;
    int dim;
} graph;