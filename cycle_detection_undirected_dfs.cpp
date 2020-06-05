#include<bits/stdc++.h>
using namespace std;

bool cycle(int v,vector<bool> &visited,const vector<int> adj[],int parent)
{
    visited[v] = true;

    for(auto u : adj[v]){
          if(!visited[u]){
             if(cycle(u,visited,adj,v)){
              return true;
            }
          }
          else if(u!=parent){
              return true;
          }
    }
    return false;
}

int main()
{
   int n,e;  cin>>n>>e;
   vector<int> adj[n];
   vector<bool> visited(n,false);
   while(e--)
   {
   	int u,v;
   	cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
   }
   bool isCycle = false;
   for(int v=0;v<n;v++){
   	   if(!visited[v]){
             if(cycle(v,visited,adj,-1)){
                  isCycle = true;
                  break;
             }
   	   }
   }
   if(isCycle){ cout<<"Graph contains a cycle!\n"; }
   else { cout<<"Graph doesn't contains a cycle\n"; }
}