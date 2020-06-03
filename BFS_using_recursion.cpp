#include <bits/stdc++.h>
using namespace std;

void bfs(queue<int> &q,vector<bool> &visited,const vector<int> adj[]) {
    if(q.empty()) return;

    auto u = q.front();  q.pop();
    cout<<u<<' ';
    for (auto v : adj[u]){
         if(!visited[v])
         {
            visited[v] = true;
            q.push(v);
         }
    }
    bfs(q,visited,adj);
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
      adj[v].push_back(u);       //Recursive BFS for undirected graph
    }
    vector<bool> visited(n,false);
    queue<int> q;
    for(int v=0;v<n;v++){
           if(!visited[v]){
               visited[v] = true;
               q.push(v);
               bfs(q,visited,adj);
           }
    }
}
