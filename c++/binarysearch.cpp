#include <bits/stdc++.h>
using namespace std; 
int binary_search(vector<int> v,int left,int right, int x){
    while(left<=right){
        int mid = left + (right - left)/2;
        if(v[mid]==x){
            return mid;
        }
        else if(v[mid]<x){
            left =mid +1;
        }
        else {
            right = mid -1;
        }
    }
    return -1;
}
int main(){
    int size;
    int number;
    vector<int>  v;
    int index;
    cout<<"enter the size of the array"<<endl;
    cin>>size;
    cout<<"enter the array numbers : "<<endl;
    for(int i=0;i<size;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    cout<<"Enter the number you want to be searched : ";
    cin>>number;
    
    index = binary_search(v, 0, size-1, number);
    if(index==-1){
        cout<<"no match found";
    }
    else {
        cout<<"number is present at index : "<<index + 1;
    }

    
}
