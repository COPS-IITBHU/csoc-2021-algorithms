#include <bits/stdc++.h>

using namespace std;

vector<int>arr;
int n,x;

int evaluate(){
    vector<int>lis(n,1);        // lis[i] represents the length of LIS ending at ith element 
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] && lis[i]<lis[j]+1)lis[i]=lis[j]+1;
        }
    }
    return *max_element(lis.begin(),lis.end());
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    cout<<"Enter the size of the array\n";
    cin>>n;
    cout<<"Now Enter the elements of the array\n";
    for(int i=0;i<n;i++){
        cin>>x;
        arr.emplace_back(x);
    }
    cout<<"The max increasing subsequence is of length "<<evaluate();
    return 0;
}

/***********************************************************************/