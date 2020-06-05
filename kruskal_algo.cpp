#include<bits/stdc++.h>
using namespace std;
class Edge{
   public:
           int source;
           int dest;
           int weight;
};
bool compare(Edge e1,Edge e2){
	return e1.weight<e2.weight;
}
    //Find
int findParent(int u,int parent[]){
    if(parent[u] == u){
    	 return u;
    }
    else findParent(parent[u],parent);
}
void kruskal(Edge input[],int n,int E){
	sort(input,input+E,compare);
    Edge output[n-1];
    
    int parent[n];
	for(int i=0;i<n;i++){
		 parent[i] = i;
	}
	int count = 0;
    int i=0;
    
    while(count != n-1){
    	Edge currentEdge = input[i];

    	  int sourceParent = findParent(input[i].source,parent);
    	  int destParent = findParent(input[i].dest,parent);
          //Union
    	  if(sourceParent != destParent){
    	  	    output[count] = currentEdge;
    	  	    count++;
    	  	    parent[sourceParent] = destParent;
    	  }
    	  i++;
    }
	
	for(int i=0;i<n-1;i++){
		cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<"\n";
	}
}

int main()
{
     int n,E;
     cin>>n>>E;
     Edge input[E];
     for(int i=0;i<E;i++){
     	    int s,d,w; cin>>s>>d>>w;
     	    input[i].source = s;
     	    input[i].dest = d;
     	    input[i].weight = w;
     }
     kruskal(input,n,E);
}