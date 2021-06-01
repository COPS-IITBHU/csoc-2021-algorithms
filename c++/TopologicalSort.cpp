#include<bits/stdc++.h>

using namespace std;

// Implementation of Topological Sorting on a Directed Acyclic Graph (DAG)

// Here we implement linear ordering of vertices of DAG such that for every directed edge a and b, vertex a comes before b in the order using modified DFS.

// Time Complexity - O(V+E)
// Space Complexity - O(N)


// Code Begins 
vector <long int> adj[100001];//Vector which stores the adjacency list

stack <long int> order;//Stack which stores the order

bool vis[100001];// Array storing state of edges (visited/unvisited)
 
void toposort(long int v)
{
    vis[v]=true;// assign the edge to visited 
    for(long long int i = 0;i<adj[v].size();i++){
        if(!vis[adj[v][i]])// Every unvisited child of the edge is visited recursively 
        toposort(adj[v][i]);
    }

    order.push(v);//Required edge is pushed in order stack
}
 
int main(){

	long int n,m;// No of vertics and edges respectively
	cin>>n>>m;

	for(long int i = 0;i<m;i++){
	    long int u,v;
	    cin>>u>>v;
	    adj[u].push_back(v);
	// vertices containing one of the edges are input in form of adjacency list
	}
	for(long int i = 1;i<=n;i++){

     //Initializing all the edges to invisited
	    vis[i]=false;
	}
	for(long int i = 1;i<=n;i++){
	    if(!vis[i]){  
	    //If the edge is unvisited then we apply toposort
	        toposort(i);
	    }
	}

 //Order is stored in stack because of stack's LIFO(Last in First Out) nature.
	while (order.empty() == false){
			cout << order.top() << " ";
			order.pop();
		}

}
