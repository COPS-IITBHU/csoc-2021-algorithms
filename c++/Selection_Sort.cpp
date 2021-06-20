#include<bits/stdc++.h>
using namespace std;

void selectionSort(int a[],int n){

    for(int i=0;i<n-1;i++){
         int min_index = i;
         for(int j=i;j<=n-1;j++){

            if(a[min_index]>a[j]){
               min_index = j;
            }
         }

     swap(a[i],a[min_index]);
    } 

}

int main(){

    int n,key;
    cin>>n;

    int a[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    selectionSort(a,n);

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }


    return 0;

}