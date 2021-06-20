#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,key;
    cin>>n;

    int a[n],i;

    for( i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<"Enter the digit u want to find "<<endl;
    cin>>key;

    for( i =0;i<n;i++){
        if(a[i]==key){
            cout<<i<<endl;
            break;
        }
    }
    if( i == n ){
        cout<<"Not found"<<endl;
    }

    return 0;

}