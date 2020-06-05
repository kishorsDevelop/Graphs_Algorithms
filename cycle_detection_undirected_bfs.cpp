#include<bits/stdc++.h>
using namespace std;
bool Cycle(int v,vector<bool> &visited,const vector<int> adj[],int n){
       vector<int> parent(n,-1);

       queue<int> q;
       visited[v] = true;
       q.push(v);

      while(!q.empty()) {
           v = q.front(); q.pop();
		       for(auto u : adj[v]){
		              if(!visited[u]){
		              	  visited[u] = true;
		              	  parent[u] = v;
		              	  q.push(u);
		              }else if(parent[v]!=u){
                          return true;
		              }   	     
           
		       }
      }
     return false;
} 	     
int main(){
	int n,e;
	cin>>n>>e;
    vector<int> adj[n];
   
	while(e--){
		int u,v;
		cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
	}
    bool isCycle = false;
    vector<bool> visited(n,false);
    for(int i=0;i<n;i++){
    	  if(!visited[i] && Cycle(i,visited,adj,n)){
                 isCycle = true;
                 break;
    	  }
    }
    if(isCycle){
    	cout<<"The Graph contains cycle\n";
    }else{
    	cout<<"The Graph doesn't contain cycle\n";
    }
}