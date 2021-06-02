


//dfs(depth first search using graph and list)

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
//int  t[1002][1002];
typedef int64_t s64;
typedef uint64_t u64;
typedef uint32_t u32;
typedef pair<int,int>ii;

// this connected component is application of dfs(depth_first_search/traversal)


class Graph
{
    public:
    // implemented through array list
    int v;
    list<int>*adj;
    Graph()
    {

    }
    Graph(int n)
    {
        this->v=n;
        this->adj=new list<int>[this->v];
    }
    void add_edges(int n1,int n2,bool bider=true)
    {
        adj[n1].push_back(n2);
        if(bider)
        {
            adj[n2].push_back(n1);
        }
    }
    //dfs implementatin 
    void dfs_helper(int src,unordered_map<int,bool>&visited)
    {
        
        visited[src]=true;
         cout<<src<<" ";
        for(auto x:this->adj[src])
        {
            if(not visited[x])
            {
                dfs_helper(x,visited);
            }
        }
    }
    
    int connected()
    {
        unordered_map<int,bool>visited;
       int result=0;
       for(int i=0;i<v;i++)
       {
           if(not visited[i])
           {  
               dfs_helper(i,visited);
               cout<<endl;
               result++;
           }
       }
    
       return result;
    }

};
int main()
{
    Graph g(6);
    g.add_edges(0,1);
    g.add_edges(2,1);
    g.add_edges(3,2);
    g.add_edges(4,5);
    cout<<endl;
    cout<<g.connected();
    return 0;
}
//Time complexity O(n+e);