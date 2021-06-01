#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        int cur = arr[i];
        int j = i-1;
        while (arr[j]>arr[i] && j>=0)
        {
            arr[i] = arr[j];
            j--;
        }
        arr[i] = cur;   
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}