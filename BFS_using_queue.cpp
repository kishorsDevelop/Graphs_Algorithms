#include <bits/stdc++.h>
using namespace std;

void bfs(int v,vector<bool> &visited,const vector<int> adj[]) {
    queue<int> q;
    q.push(v);
    visited[v] = true;
    while(!q.empty())
    {
          v = q.front(); q.pop();
          cout<<v<<" "; 
          for(auto u : adj[v]){
                  if(!visited[u]){
                      visited[u] = true;
                      q.push(u);
                  }
          }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    vector<int> adj[n];

    while(e--){
      int u,v;
      cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);       //Iterative BFS for undirected graph
    }
    vector<bool> visited(n,false);
    for(int v=0;v<n;v++){
           if(!visited[v]){
               bfs(v,visited,adj);
           }
    }
}
