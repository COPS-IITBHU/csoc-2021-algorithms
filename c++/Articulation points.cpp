#include <bits/stdc++.h>
#define MAX_N 100001
using namespace std;

vector<int> adj[MAX_N];                   //Adjacency list representation of undirected graph
int timer=0;                              //timer to keep updating the in-time of nodes using dfs
vector<int> low(MAX_N,0);                 //Stores the min in-time of a directly connected node for every node.
vector<int> in(MAX_N,0);                  //Stores the in-time of every node during dfs
bool visited[MAX_N]{false};               //Keeps track of visited nodes(Intially no node is visited)
set<int> AP;                              //Set to store the articulation points

void dfs(int node, int p=-1)
{
	int a=0;                               //Counts the no. of unvisited children
	visited[node]=true;                    //Marking the current node as visited
	in[node]=low[node]=timer++;            //Updating the in and low time of current node
	for(int child:adj[node])
	{
		if(child==p) continue;             //We don't minimise the low time with parent
		if(!visited[child])
		{
			a++;                           //incrementing unvisited child count
			dfs(child,node);
			if(low[child]>=in[node] && p!=-1) AP.insert(node);         //If low time of child is greater, then it is not 
                                                                //connected with any node above the current node, hence it is an AP 
			low[node]=min(low[node],low[child]);                       //Minimise the low time of current node, anyways
		}
		else
		{
			low[node]=min(low[node],in[child]);                 //If child was already visited, minimise the low time.
		}
	}
	if(p==-1 && a>1)                                           // The root is an AP iff it has more than one connected component
	{
		AP.insert(node);
	}
}

int main()
{
    int n,m;
    cout<<"Enter the number of nodes in the undirected graph:\n";
    cin>>n;
    cout<<"Enter the number of edges in the undirected graph:\n";
    cin>>m;
	while(m--)
	{
		cout<<"Enter the edge of graph as space seperated vertices:\n";
        int a,b;
        cin>>a>>b;
		adj[a].push_back(b); adj[b].push_back(a);
	}
	dfs(1);                                                  //Assuming 1 based indexing of nodes
	cout<<AP.size()<<" articulation point(s) found:\n";
	for(auto it=AP.begin(); it!=AP.end(); it++)
	{
		cout<<*it<<" ";
    }
	return 0;
}
