#include <bits/stdc++.h>
using namespace std;
int lcs(string , string) ;
int main()
{
    string s1,s2 ;
    cin>>s1>>s2 ;

    cout<<lcs(s1,s2) ;
}

int lcs(string s1,string s2)
{
    if(s1 == s2)
        return s1.size() ;

    int m = s1.size() ;
    int n = s2.size() ;

    int dp[m+1][n+1] ; // 2d array for stroring the lcs of the strings with i, j lengths respectively.

    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0) // length of longest common subsequence when either string is empty or both is empty
                dp[i][j] = 0 ;
            else if(s1[i] == s2[j])
            {
                dp[i][j] = 1+dp[i-1][j-1] ;//adding one to the length if the char at positions are equal .
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]) ;
            }
        }
    }
    return dp[m][n] ;
}

