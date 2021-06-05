#include<bits/stdc++.h>
using namespace std;
int binary_search(int arr[],int n, int x){
    int ri=n-1;         //ri=right index
    int li=0;           //li=left index
    int mid;
    while(li<=ri){
        mid=li+(ri-li)/2;             
        if(arr[mid]>x)
            ri=mid-1;
        else if(arr[mid]<x)
            li=mid+1;
        else if(arr[mid]==x)
            return mid;
    }
    return -1;
}
int main(){
    int n;
    cin>>n;         //taking the size of array as input

    //creating array of size n
    int arr[n];

    //taking input of n length array
    for(int i=0;i<n;i++){
        cin>>arr[i];          
    }
    sort(arr,arr + n);
    int x;
    cin>>x;             //enter the number to be searched

    //index variable store the index where x is present in the array.
    //binary_search is a function which applies the binary search algorithm on the given array. 
    int index = binary_search(arr,n,x);    

    //output based on the return value from the function binary_search                                            
    if(index==-1)
        cout<<"Entered number is not present in the array."<<endl;
    else 
        cout<<"Entered number is present at index "<<index<<" in the array."<<endl;
    return 0;    
}