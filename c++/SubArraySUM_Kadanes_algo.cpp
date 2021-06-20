#include<bits/stdc++.h>
using namespace std;
int main(){
    int i,curr_sum = 0 , max_sum =0,n;
    cin>>n;

    int a[n];
    
    for(i=0;i<n;i++){
        cin>>a[i];
    }

    for(i=0;i<n;i++){
        curr_sum = curr_sum + a[i];

        if(curr_sum<0){
            curr_sum = 0;
        }

        max_sum = max(max_sum, curr_sum);       //this max funt'n gives the maximum of the two values among these 2 variables
    }

    cout<<"maximum sum of a subarray is: "<<max_sum<<endl;

return 0;

}