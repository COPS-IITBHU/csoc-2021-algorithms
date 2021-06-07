#include <bits/stdc++.h>
using namespace std;
class Graph{
    
    map<int,list<int> > gr;
    public:

    void addEdges(int x,int y)
    {
        gr[x].push_back(y);
    }

    int snakes_and_ladders()
    {
        map<int,int> dist;
        for(auto node_pair:gr)
        {
            int node=node_pair.first;
            dist[node]=INT_MAX;
        }
        queue<int> q;
        q.push(1);
        dist[1]=0;

        while(!q.empty())
        {
            int curr_node=q.front();
            q.pop();
            
            for(auto nbr:gr[curr_node])
            {
                if(dist[nbr]==INT_MAX)
                {
                    q.push(nbr);
                    dist[nbr]=dist[curr_node]+1;
                }
            }


        }
        return dist[100];




    }

    
};
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        Graph g;
        int board[107]={0};
        int n;  //No. of ladders
        cin>>n;
        while(n--)
        {
            int x,y;
            cin>>x>>y;
            board[x]=abs(x-y);
        }
        int m;
        cin>>m;
        while(m--)
        {
            int x,y;
            cin>>x>>y;
            board[x]=-abs(x-y);
        }

        for(int i=1;i<=100;i++)
        {
            for(int j=1;j<=6;j++)
            {
                int dice=i+j;
                dice+=board[i+j];
                if(dice<=100)
                {
                    g.addEdges(i,dice);
                }
            }

        }
        g.addEdges(100,100);
        int ans=g.snakes_and_ladders();
        if(ans==INT_MAX)
        cout<<-1;
        else
        cout<<ans;
        
      

    cout<<endl;
    }



}
