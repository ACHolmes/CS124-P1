// Typedefs for structs
typedef struct node node;
typedef struct edge edge;

typedef struct node{
    int n;
    float x;
    float y;
    float z;
    float w;
    node * next;
} node;

typedef struct edge{
    float weight;
    int from;
    int to;
    edge * next;
} edge;

typedef struct graph{
    node* nodes;
    edge* edges;
    int dim;
} graph;