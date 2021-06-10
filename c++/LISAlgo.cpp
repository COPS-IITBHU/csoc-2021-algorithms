/*					LONGEST INCREASING SUBSEQUENCE 					*/
#include "bits/stdc++.h"
using namespace std;

//Defined MACROS for easy and Convenient Coding
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define int               long long
#define mem1(a)           memset(a,-1,sizeof(a))
const int N=1e6;


int LIS(int arr[],int n);
//Array used for memoization
int stored[N];

//MAIN Function
signed main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(0);cout.tie(0);

	mem1(stored);
	cout<<"Enter Length of Integer Array : ";
    int n;cin>>n;

    int arr[n];
    cout<<endl;
    rep(i,0,n) cin>>arr[i];
    
    int lis=LIS(arr,n);
    cout<<"The Length of Longest Increasing Subsequence in given array is : "<<lis<<endl;
    return 0;
}


//The Recursive Function to find the LIS
int LIS(int arr[],int n){
    if(n==0){
        return 1;
    }
    if(stored[n-1]!=-1){
        return stored[n-1];
    }
    int highest=1;

    rep(i,0,n-1){
        if(arr[i]<arr[n-1]){
            highest=max(highest,LIS(arr,i)+1);
        }
    }
    return stored[n-1]=highest;
}