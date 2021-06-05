
/*          THIS CODE IS WRITTEN BY ME . 
             algorithm choosen is "Dynamic Programming and Backtracking" 
             SHUBHAM KUMAR
             Handle :- shubh2103
             question - Longest Common Subsequence
*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int max(int *a , int *b){
    if(*a>*b)
    return *a;
    else 
    return *b;
}

int longest_common_subsequence(int i , int j , string s1 , string s2 , vector<vector<int>> &v){
    if(i>=s1.size() or j>=s2.size()){
        return 0;
    }
    if(v[i][j]!=-1){
        return v[i][j];
    }
    if(s1[i]==s2[j]){
        return 1+longest_common_subsequence(i+1,j+1,s1,s2,v);
    }
    else{
        int l= longest_common_subsequence(i+1 , j , s1 , s2 , v);
        int r= longest_common_subsequence(i , j+1 , s1 , s2 , v);
        return v[i][j] = max(&l,&r);
    }
}

int main(){

    string s1 , s2;

    cin>>s1;
    cout<<endl;
    cin>>s2;

    int x= s1.size();
    int y= s2.size();

    vector<vector<int>> v(x , vector<int>(y , -1));

    cout<<longest_common_subsequence(0 , 0 , s1 , s2 , v);
    
    return 0;

}