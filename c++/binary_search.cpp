//Rohit 

#include<bits/stdc++.h>
using namespace std;

int binarySearch(int a[],int n,int key){
 int s=0,mid,e= n-1;

    while(s<=e){
    
        mid=(s+e)/2;

        if(a[mid]==key){
            return mid;     //will return the value of the index and loop and funt'n will stop here
        }
        else if (a[mid]>key){
            e = mid - 1;
        }
        else if(a[mid]<key){
            s = mid+1;
        }

    }

    return -1;     // -1 means not found
}
int main(){

    int n,key;
    cin>>n;

    int a[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<"Enter the digit u want to find "<<endl;
    cin>>key;

    cout<<binarySearch(a,n,key);

    return 0;

}