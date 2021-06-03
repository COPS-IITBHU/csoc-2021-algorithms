#include<bits/stdc++.h>
using namespace std;
    int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //defining variables
    int n,start,end;
    vector<vector<int>> act;

    //Taking input from user
    cout<<"Enter the no of activities"<<endl;
    cin>>n;

    cout<<"Enter the start and end time of the activities"<<endl;
    for(int i=0;i<n;i++){
        cin>>start>>end;
        act.push_back({start,end});
    }
    sort(act.begin(),act.end(),[&](vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    });

    int first =1;
    int actend = act[0][1]; 
  
    //Iterating if the condition is satisfied ( start time of (activity + 1) > end time of (activity))
    cout<<"The activities which r executed:";
    for(int i=0;i<n;i++){
        if(act[i][0]>=actend){
            first++;
        }
    }
    cout<<first;
    return 0;
}
