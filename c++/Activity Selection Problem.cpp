#include<bits/stdc++.h>
using namespace std;
// intially taking no. of activites as input.
int main(){
    int n;
    cin>>n;
    // this vector will hold all the start and end time for  all the activities.
    vector<vector<int>> A;
    for(int i=0;i<n; i++){
        int St,Et;
        cin>>St>>Et;
        A.push_back({St,Et});
    }
//sorting all activities according to time.
    sort(A.begin(),A.end(),[&](vector<int> &a, vector<int> &b){
        return a[1]<b[1];

    });
    // taking 1st activity.
    int take= 1;
    int Et = A[0][1];
    for (int i=1;i<n;i++){
         if(A[i][0]>= Et){
             take++;
             Et = A[i][1];
         }
    }
    //this gives us the max no. of activites that can be performed.
    cout<<take<<"\n";
    
}

