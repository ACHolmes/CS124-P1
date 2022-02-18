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

float Prim(float* edges, int n, int dim)
{
	return 0.0;
}