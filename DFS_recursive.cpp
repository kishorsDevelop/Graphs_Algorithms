#include <bits/stdc++.h>
using namespace std;

void dfs(int v,vector<bool> &visited,const vector<int> adj[]) {
     visited[v] = true;
     cout<<v<<" ";
     for(auto u : adj[v]){
          if(!visited[u]){
              dfs(u,visited,adj);
          }
     }
}
int main()
{
    int n,e;    // n = vertices  , e = edges
    cin>>n>>e;
    vector<int> adj[n];

    while(e--){
      int u,v;
      cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);       //Iterative DFS for undirected graph
    }
    vector<bool> visited(n,false);
    for(int v=0;v<n;v++){
           if(!visited[v]){
               dfs(v,visited,adj);
           }
    }
}
