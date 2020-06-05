#include<bits/stdc++.h>
using namespace std;
bool Cycle(int n,const vector<int> adj[]){
     vector<int> inDegree(n,0);
     for(int v=0;v<n;v++){
           for(auto u : adj[v]){
                  inDegree[u]++;
           }
     }
     queue<int> q;
     for(int v=0;v<n;v++){
          if(inDegree[v] == 0){
            q.push(v);
          }
     }
     int cnt = 0;
     std::vector<int> top_order;
     while(!q.empty()){
                int v = q.front(); q.pop();
                top_order.push_back(v);
                for(auto u : adj[v]){
                        if(--inDegree[u] == 0){
                          q.push(u);
                        }
                }
        cnt++;
     }
     if(cnt!=n){
      return true;
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
	}

    if(Cycle(n,adj))
    {
    	cout<<"The Graph contains cycle\n";
    }else{
    	cout<<"The Graph doesn't contain cycle\n";
    }
}