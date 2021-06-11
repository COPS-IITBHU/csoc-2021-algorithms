#include<bits/stdc++.h>
using namespace std;
vector <vector <int> > adj(10) ;
vector <bool> visited(10) ;
void dfs(int v)
{
    visited[v] = true ;
    cout<<v<<" -> ";
    for( auto u: adj[v]){
        if(visited[u]==0){
            dfs(u);
        }
    }
}
int main()
{
    int nodes,edges,x,y , a ;
    cin >> nodes ;
    cin >> edges ;
    for(int i =0 ;i<edges;i++)
    {
        cin >> x >> y ;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    for(int i=0;i<nodes;i++)
    {
        visited[i]=false;
    }
    cin>>a;
    dfs(a);
    return 0;
}
