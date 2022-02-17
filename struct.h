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

/*
node* generateNodesStatic(int n, int dim);
node* generateNodesHeap(int n, int dim);
edge* generateEdgesStatic(node* list, int n);
float MST(node* nodes, edge* edges, int dim);


node* generateNodesStatic(int n, int dim)
{
    node list[n];
    float temp[4] = {0};
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < dim; j++)
        {
            temp[i] = rand01();
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
    if(!start)
    {
        return NULL;
    }
    node* cursor = start;
    for(int i = 0; i < n; i++){
        //logic needed here
        cursor += sizeof(node);
    }

}*/