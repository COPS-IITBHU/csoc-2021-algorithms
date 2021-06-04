#include<bits/stdc++.h>
using namespace std;
int __long_subseq(int arr[], int n, int* x)
{
   
    if (n == 1){
        return 1;
    }
    int y, m = 1;
    for (int i = 1; i < n; i++) {
        y = __long_subseq(arr, i, x);
        if ( y + 1 > m and arr[i - 1] < arr[n - 1]){
            m = y + 1;
        }
    }
    if (*x < m){
        *x = m;
    }
 
    return m;
}

int long_subseq(int arr[], int n)
{
    int max = 1;
    __long_subseq(arr, n, &max);
    return max;
}


int main()
{   int n;
    cout<<"enter size of array "<<endl;
    cin>>n;
    cout<<" enter integral elements of the array "<<endl;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Length of longest increasing subsequence is : "<<long_subseq(arr,n);















    
    return 0;
}
