#include <bits/stdc++.h>
using namespace std;

// Recursive DP with Memoization (Top Down Approach)  Time Complexity O(n*m)
vector<vector<int>> dp(2005,vector<int>(2005,-1));
int edit_distance_recursive(string a, string b, int n, int m)
{
    if(m==0) return n;  // If string 2 is empty then insert all character of string 1
    if(n==0) return m;  // If string 1 is empty then insert all character of string 2

    int &ans=dp[n][m];
    if(ans!=-1) return ans;    // If dp[i][j] is already computed before then return result else store 

    if(a[n-1]==b[m-1])   //If at ith index both are same no operations needed to be performed 
    {
        return ans=edit_distance_recursive(a,b,n-1,m-1); 
    }
    // Consider all possible Operations 
    int insert = edit_distance_recursive(a,b,n,m-1); 
    int remove = edit_distance_recursive(a,b,n-1,m);
    int replace = edit_distance_recursive(a,b,n-1,m-1); 

    return ans=1+min({insert,remove,replace});
}

// Iterative DP (Bottom Up Approach) Time Complexity O(n*m)
int edit_distance_iterative(string a, string b, int n, int m)
{
    int dp[n+1][m+1];    //For Storing Results 
    for(int i=0; i<=n; i++)
     {
        for(int j=0; j<=m; j++) 
        {
            // If string 1 is empty then insert all character of string 2
            if(i==0) dp[i][j]=j; 
 
            // If string 2 is empty then insert all character of string 1
            else if(j==0) dp[i][j] = i; // Min. operations = i
 
            //If at ith index both are same no operations needed to be performed 
            else if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1];
 
            // Consider all possible Operations Insert, Remove, Replace
            else dp[i][j]= 1+ min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]}); 
        }
    }
    return dp[n][m];
}
int main()
{
    string a, b;   cin>>a>>b;    // Input String 1 and 2
    int n=a.size()-1, m=b.size()-1; 
    cout<<edit_distance_recursive(a,b,n,m)<<"\n";    // Edit Distance with Recursion + Memoization 
    cout<<edit_distance_iterative(a,b,n,m)<<"\n";    // Edit Distance with Iteration
} 