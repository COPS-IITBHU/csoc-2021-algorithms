#include <iostream>
#include <map>
#include <list>
#include <set>
using namespace std;

class Graph{
    map<int, list<pair<int, int>>> m;

public:
    void makeAdjList(int a, int b, int c, bool bidirectional = true){
        m[a].push_back({b, c});
        if(bidirectional)
            m[b].push_back({a, c});
    }

    void showGraph(){
        for(auto i = m.begin() ; i != m.end() ; i++){
            cout<<"Vertex "<<i->first<<"-> ";
            for(auto j: m[i->first]){
                cout<<"("<<j.first<<", "<<j.second<<") ";
            }
            cout<<endl;
        }
    }

    void dijkstraAlgorithm(int source){
        map<int, int> distanceMap;
        for(auto i : m)
            distanceMap[i.first] = INT_MAX;

        distanceMap[source] = 0;

        set<pair <int, int>> minDistance;
        minDistance.insert({0, source});

        while(!minDistance.empty()){
            auto p = *(minDistance.begin());
            int node = p.second;

            int nodeDistance = p.first;

            for(auto neighbour : m[node]){
                int neighbourNode = neighbour.first, neighbourDistance = neighbour.second;

                if((nodeDistance + neighbourDistance) < distanceMap[neighbourNode]){
                    auto itr = minDistance.find({distanceMap[neighbourNode], neighbourNode});

                    if(itr != minDistance.end())
                        minDistance.erase(itr);

                    distanceMap[neighbourNode] = nodeDistance + neighbourDistance;
                    minDistance.insert({distanceMap[neighbourNode], neighbourNode});
                }
            }

            minDistance.erase(minDistance.begin());
        }

        for(auto i : distanceMap)
            cout<<i.first<<" -> "<<i.second<<endl;

    }
};


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    Graph g;
    int t, x, y, z, k;
    cin>>t;

    while(t--){
        cin>>x>>y>>z>>k;
        g.makeAdjList(x, y, z, k);
    }

    // g.showGraph();
    // cout<<endl<<"----"<<endl<<endl;
    g.dijkstraAlgorithm(1);

    return 0;
}

// test case
// 8
// 1 2 1 0
// 1 3 4 0
// 2 3 1 1
// 3 4 2 1
// 1 4 7 1
// 5 2 4 0
// 3 5 1 1
// 4 2 3 1
