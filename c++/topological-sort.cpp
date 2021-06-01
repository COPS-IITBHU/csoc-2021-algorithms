#include <bits/stdc++.h>
using namespace std;

#define endl            <<"\n"
#define in              cin>>
#define out             cout<<
#define pb              push_back
#define mp              make_pair
#define rep(i,a,b)      for (int i=a;i<b;i++)
#define vvi             vector<vector<int>>
#define vi              vector<int>

void topoSortHelper(bool visited[], int v, vector<int> adj[], vector<int> &sorted)
{
    visited[v] = 1;

    for (auto i=adj[v].begin(); i!=adj[v].end(); i++)
    {
        if (!visited[*i]) 
        {
            topoSortHelper(visited, *i, adj, sorted);
        }
    }
    sorted.pb(v);
}

vector<int> topoSort(int V, vector<int> adj[]) 
{
    bool visited[V] = {0};
    vector<int> sorted;

    for (int i=0;i<V;i++)
    {
        if (!visited[i])
        {
            topoSortHelper(visited, i, adj, sorted);
        }
    }

    reverse(sorted.begin(), sorted.end());
    return sorted;
}

void addEdge(int n, int e, vector<int> adj[])
{
    adj[n].pb(e);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Enter the number of nodes and edges 
    int n,e; in n>>e;
    vector<int> adj[n];

    // Numbering of nodes start from 0 to n-1
    for (int i=0;i<e;i++)
    {
        int x,y; in x>>y; // x and y between 0 and n-1
        addEdge(x,y,adj);
    }

    vector<int> sorted = topoSort(n, adj);
    rep(i,0,sorted.size()) 
    {
        out sorted[i]<<" ";
    }
    cout endl;

    return 0;
}
