#include "bits/stdc++.h"
using namespace std;
int linearSearch(int arr[],int val,int n)
{
    int key;
   for (int i = 0; i < n; i++)
   {
       if(arr[i]==val)
       {
           key=i;
           break;
       }
   }
   return key;
   
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int searchVal;
    cin>>searchVal;
    if(linearSearch(arr, searchVal,n))
    {
        cout<<linearSearch(arr, searchVal,n)<<" is present" ;
    }
    else{
        cout<<linearSearch(arr, searchVal,n
    }
}