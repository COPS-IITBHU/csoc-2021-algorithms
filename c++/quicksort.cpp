#include<bits/stdc++.h>
using namespace std;
int part(int arr[], int small, int large);
void quickSort(int arr[], int small, int large);
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    quickSort(arr, 0, n - 1);
    cout<<endl;
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    return 0;
}
int part (int arr[], int small, int large)
{
    int pivot = arr[large];
    int i = (small - 1); 
 
    for (int j = small; j <= large - 1; j++)
    {
        
        if (arr[j] < pivot)
        {
            i++; 
            int t= arr[i];
            arr[i]=arr[j];
            arr[j]=t;
        }
    }
   int t=arr[i+1];
   arr[i+1]=arr[large];
   arr[large]=t;
    return (i + 1);
}
void quickSort(int arr[], int small, int large)
{
    if (small < large)
    {
        
        int pi = part(arr, small, large);
 
        
        quickSort(arr, small, pi - 1);
        quickSort(arr, pi + 1, large);
    }
}