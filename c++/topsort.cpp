#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <long long> ans,adj[100001];
bool vis[100001];
 
void DFS(long long v);

int main()
{
long long n,m;
cin>>n>>m;
for(long long i = 0;i<m;i++)
{
    long long u,v;
    cin>>u>>v;
    adj[u].push_back(v);
}
for(long long i = 1;i<=n;i++)
{
    vis[i]=false;
}
for(long long i = 1;i<=n;i++)
{
    if(!vis[i])
    {
        DFS(i);
    }
}
reverse(ans.begin(),ans.end());
for(auto x : ans)
cout<<x<<" ";
}

void DFS(long long v)
{
    vis[v]=true;
    for(long long i = 0;i<adj[v].size();i++)
    {
        if(!vis[adj[v][i]])
        DFS(adj[v][i]);
    }
    ans.push_back(v);
}
 