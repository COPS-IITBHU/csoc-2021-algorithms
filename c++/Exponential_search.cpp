#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int , int , int );
int exponentialSearch(int arr[], int n, int e)
{
    if(arr[0] == e)
        return 0;
    int i=1;
    while(i<=n && arr[i] <= e)
        i = i*2;

    return binarySearch(arr, i/2, min(i,n-1), e);
}
int binarySearch(int arr[], int l, int r, int e)
{
    if(r>=l)
    {
        int mid = l + (r-1)/2;
        if(arr[mid] == e)
            return mid;
        if(arr[mid] < e)
            return binarySearch(arr, mid +1, r, e);
        else
            return binarySearch(arr, l, mid-1, e);
    }
    return -1;
}
int main()
{
    int n,a,x;
     cout<<"Enter number of elements:";
     cin>>n;
     int arr[n],i;
     for(int i=0;i<n;i++)
     {
         cin>>arr[i];
     }
     sort(arr , arr+n);
     cout<<"Your sorted array is:"<<endl;
     for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
     cout<<endl<<"Enter the element to be found: ";
     cin>>a;
     x = exponentialSearch(arr, n , a);
      if(x==-1)
        cout<<"Element not found";
     else
        cout<<"The element is in position: "<<x+1;
     return 0;
}
