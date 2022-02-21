#include "weight.h"
#include "string.h"

/*def Prim(G, length: E(G) → ℝ, s ∈ V(G)):
	vertices_to_explore = [s: 0]		//priority queue
	S = {}						//vertices in tree
	dist = {s: 0, other vertices: ∞}	//distances from S
	prev = {s: null}					//previous vertex in tree
	while vertices_to_explore != []:
		v = deletemin(vertices_to_explore)
	for (v,w) in E where w not in S:
			if dist[w] > length(v,w):
				prev[w] = v		
				dist[w] = length(v,w)
				insert(w,dist[w],vertices_to_explore)*/

float distance(node* n1, node* n2, int dim)
{
    float w;
    switch(dim)
    {
        case 1:
            w = abs(n1->x - n2->x);
            return w;
        case 2:
            w = sqrt(( ( pow(n1->x - n2->x, 2.0) ) + ( pow(n1->y  - n2->y, 2) ) ));
            return w;
        case 3:
            w = sqrt(( ( pow(n1->x - n2->x, 2) ) + ( pow(n1->y  - n2->y, 2) )
                    + ( pow(n1->z  - n2->z, 2) ) ));
            return w;
        case 4:
            w = sqrt(( ( pow(n1->x - n2->x, 2) ) + ( pow(n1->y  - n2->y, 2) )
                           + ( pow(n1->z - n2->z, 2) ) + ( pow(n1->w  - n2->w, 2) ) ));
            return w;
    }
    printf("Invalid dimension \n");
    return 0.0;
}

// This isn't an efficient way of doing things
// Should improve on this to improve runtime
node* ithNode(node* head, int n)
{
    if (n == 0)
    {
        return head;
    }
    for (int i = 0; i < n; i++)
    {
        head = head->next;
    }
    return head;
}

float prim(node* nodes, int n, int dim)
{
    float distances[n];
    int minIndex = 0;
    node* node2;
    // Set start node distance of -1 so we never loop back to it
    distances[0] = -1.0;
    // Everything else 3.0, impossibly far away so essentially infinity
    for (int i = 1; i < n; i++)
    {
        distances[i] = 3.0;
    }
    // Running total
    float total = 0.0;
    // start with the first node
    node* node = nodes;

    // We are going to add n-1 edges
    for (int i = 0; i < n - 1; i++)
    {
        // each time we add a new vertex, we need to check if that 
        // gets us a shorter path to any of the other verties
        for (int j = 0; j < n; j++)
        {
            // if the node hasn't already been visited and isn't itself, 
            // we should check if this new node can get there 
            // via a cheaper route using the most recently added node
            if(distances[j] > -0.5 && j != node->n)
            {
                node2 = ithNode(nodes, j);
                float dist = distance(node, node2, dim);
                if ( dist < distances[j])
                {
                    distances[j] = dist;
                }
            }
        }
        float min = 3.0;
        // Find the shortest path available to us after this set of updates
        for (int k = 0; k < n; k++)
        {
            if (distances[k] < -0.5)
            {
                continue;
            }
            if (distances[k] < min)
            {
                min = distances[k];
                minIndex = k;
            }
            // Useful for debugging
            //printf("min: %f   ", min);
        }
        // Use the shortest distance available
        total += distances[minIndex];
        // The next node to check its edges is the one we just added
        node = ithNode(nodes, minIndex);
        // Set it to have distance -1 so we don't go back to it ever.
        distances[node->n] = -1.0;
    }
    return total;
}
