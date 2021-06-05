#include <bits/stdc++.h>
using namespace std;

//Function for comparing activities in the increasing order of finishing time
bool Activycompare(pair <int,int> p1, pair <int,int> p2){
    return (p1.second < p2.second);
}

int main(){
    int n;
    cin>>n;
    int AS[n];
    int AF[n];
    int i;
    vector <pair <int,int>> v;
    
    //Initialising start and finish time for each activity as two different arrays
    for(i=0;i<n;i++){
        cin>>AS[i];
    }
    for(i=0;i<n;i++){
        cin>>AF[i];
    }

    //Pushing back each pair in a vector
    for(i=0;i<n;i++){
        v.push_back({AS[i],AF[i]});
    }

    sort(v.begin(),v.end(),Activycompare);

    cout<<"ANS:"<<"\n";
    cout<<v[0].first<<","<<v[0].second<<"\n";
    i=0;
    for(int j=1;j<v.size();j++){
        if(v[j].first>=v[i].second){// if the starting time of next activity is greater than or equal to the previous initialised activity, then initialise the next activity
            cout<<v[j].first<<","<<v[j].second<<"\n";
            i=j;
        }
    }
    return 0;
}