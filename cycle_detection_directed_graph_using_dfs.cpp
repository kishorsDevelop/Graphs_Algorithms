#include<bits/stdc++.h>
using namespace std;

bool cycle(int v,vector<bool> &visited,vector<bool> &recStack,const vector<int> adj[]){
   
      if(!visited[v]){
      	   visited[v] = true;
      	   recStack[v] = true;

      	   for(auto u : adj[v]){

              if(!visited[u] && cycle(u,visited,recStack,adj)){  return true; }
              
              else if(recStack[u]){ return true; }
      	   }
        recStack[v] = false;
        return false;
      }
}

int main()
{
   int n,e;  cin>>n>>e;
   vector<int> adj[n];
   vector<bool> visited(n,false);
   vector<bool> recStack(n,false);
   while(e--)
   {
   	int u,v;
   	cin>>u>>v;
    adj[u].push_back(v);
   }
   bool isCycle = false;
   for(int v=0;v<n;v++){
   	   if(!visited[v]){
             if(cycle(v,visited,recStack,adj)){
                  isCycle = true;
                  break;
             }
   	   }
   }
   if(isCycle){ cout<<"Graph contains a cycle!\n"; }
   else { cout<<"Graph doesn't contains a cycle\n"; }
}