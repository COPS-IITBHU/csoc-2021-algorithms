#include "bits/stdc++.h"
using namespace std;
int linearSearch(int arr[],int val,int n)
{
    int key=-1;
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
    if(0<=linearSearch(arr, searchVal,n)<=n)
    {
        cout<<searchVal<<" is present" ;
    }
    else{
        cout<<searchVal<<" is not present" ;
    }
}