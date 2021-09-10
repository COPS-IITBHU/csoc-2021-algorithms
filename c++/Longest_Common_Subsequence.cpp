/*Longest Common Subsequence Algorithm*/

#include <bits/stdc++.h>
using namespace std;

#define ll             long long 
#define int            long long
#define pb             push_back
#define endl           "\n"
#define F              first
#define S              second
#define popcount(x)    __builtin_popcountll(x)
typedef unsigned long long ull;
 

const int M=1000000007;
const int MM=998244353;
const int INF =9e18;

int lcs(string a,string b,int m,int n)
{
   if(m==0||n==0)
    return 0;
   if(a[m-1]==b[n-1])
    return (1LL+lcs(a,b,m-1,n-1));
   int x=lcs(a,b,m,n-1);
   int y=lcs(a,b,m-1,n);
   return max(x,y);

}
signed main()
{
    string a,b;
    cin>>a>>b;
    int m=a.size(),n=b.size();
    int ans=lcs(a,b,m,n);
    cout<<"Length of Longest common subsequence of "<<a<<" and "<<b<<" is :"<<ans;
}

/*_*/
