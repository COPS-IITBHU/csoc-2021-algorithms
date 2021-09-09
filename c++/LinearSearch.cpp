#include<bits/stdc++.h>
using namespace std;

bool LinearSearch(int search, vector<int> &arr)
{
    for(auto it: arr)
    {
        if(it==search)
        return true;
    }
    return false;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
    }
    int search;
    cin>>search;
    if(LinearSearch(search,arr))
    {
        cout<<"Present";
    }
    else{
        cout<<"Not Present";
    }
}