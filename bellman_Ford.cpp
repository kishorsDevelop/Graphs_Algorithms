#include<bits/stdc++.h>
#include<vector>
struct Edge
{
	int source,dest,weight;
};
void bellman_ford(vector<Edge> &edges,int n,int e,int src){

	vector<int> distance (n, INT_MAX);
	distance[src] = 0;

	vector<int> parent (n, -1);

	int u, v, w, k = n;

	// Relaxation step (run V-1 times)
	while (--k)
	{
		for (int j = 0; j < e; j++)
		{		
			u = edges[j].source, v = edges[j].dest;
			w = edges[j].weight;
			
			
			if (distance[u] != INT_MAX && distance[u] + w < distance[v])
			{
				distance[v] = distance[u] + w;
				parent[v] = u;
			}
		}
	}

	for (int i = 0; i < e; i++)
	{	
		u = edges[i].source, v = edges[i].dest;
		w = edges[i].weight;
	
		if (distance[u] != INT_MAX && distance[u] + w < distance[v])
		{
			cout << "Negative Weight Cycle Found!!";
			return;
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << "Distance of vertex " << i << " from the source is "
			 << setw(2) << distance[i]<<"\n";
	}
}


int main()
{
	vector<Edge> graph;
	int n,e; cin>>n>>e;
	while(e--){
		int u,v,wt;  cin>>u>>v>>wt;
		graph.push_back({u, v, wt});
	}
	bellman_ford(graph,n,e,0);
}