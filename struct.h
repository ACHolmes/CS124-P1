// Typedefs for structs
typedef struct node2 node2;
typedef struct node3 node3;
typedef struct node4 node4;
typedef struct edge edge;

typedef struct node2{
    int n;
    float x;
    float y;
    node2 * next;
} node2;

typedef struct node3{
    int n;
    float x;
    float y;
    float z;
    node3 * next;
} node3;

typedef struct node4{
    int n;
    float x;
    float y;
    float z;
    float w;
    node4 * next;
} node4;


typedef struct edge{
    float weight;
    int from;
    int to;
    edge * next;
} edge;

typedef struct graph2{
    node2* nodes;
    edge* edges;
    int dim;
} graph2;

typedef struct graph3{
    node3* nodes;
    edge* edges;
    int dim;
} graph3;

typedef struct graph4{
    node4* nodes;
    edge* edges;
    int dim;
} graph4;
