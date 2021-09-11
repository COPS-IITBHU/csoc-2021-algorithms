#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"enter size of array : ";
    cin>>n;
    int arr[n];
    cout<<endl<<"enter elements of array"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    //bubblesort
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
    cout<<endl<<"sorted array is: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

}