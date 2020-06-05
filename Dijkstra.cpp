#include<bits/stdc++.h>
#define INF 0x3f3f3f
using namespace std;
typedef pair<int,int> ipair;

void Dijkstra(vector<ipair> adj[],int n,int src){
    priority_queue< ipair,vector<ipair>,greater<ipair> > pq;
    vector<int> dist(n,INF);
    pq.push(make_pair(0,src));
    dist[src] = 0;

    while(!pq.empty()){
    	    int v = pq.top().second; pq.pop();
    	    for(auto x : adj[v]){

    	    	    int u = x.first;
    	    	    int weight = x.second;

    	    	    if(dist[u] > dist[v] + weight){
    	    	    	dist[u] = dist[v] + weight;
    	    	    	pq.push(make_pair(dist[u],u));
    	    	    }
    	    }
    }
    cout<<"vertex"<<" "<<"distance"<<"\n";
    for(int i=0;i<n;i++){
    	  cout<<i<<" "<<dist[i]<<"\n";
    }
 
}

int main()
{
    int n,e;
    cin>>n>>e;
    vector<ipair> adj[n];
        while(e--)
        {
    	   int u,v,wt; cin>>u>>v>>wt;
           adj[u].push_back(make_pair(v,wt));
           adj[v].push_back(make_pair(u,wt));
        }            //src
        Dijkstra(adj,n,0);
    return 0;
}
