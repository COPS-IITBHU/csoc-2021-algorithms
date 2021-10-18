// author : Darshil Agrawal (sherdil0023)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define M 1000000007

ll fun(ll p[], ll w[], ll W, ll n)          // a knap-sack function returning maximum profit for the given weight
{   
    ll dp[n+1][W+1];                        
    for(ll i = 0 ; i <= n; i++)
    {
        for(ll j = 0 ; j  <= W; j++)
        {
            if(j==0 or i==0) dp[i][j] = 0;
            else if(j < w[i-1]) dp[i][j] = dp[i-1][j];              
            else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i-1]]+p[i-1]);
            }
        }
    }
    return dp[n][W];
}

int main()
{
    ll testcase;
    cin >> testcase;
    while(testcase--)
    {
    ll n, w;                // n = no of elements , w = max weight 
    cin >> n >> w;
    ll pro[n], wgt[n];      // pro : profit array , wght = weight array
    for(ll i = 0; i < n; i++)
    {
        cin >> pro[i];
    }
    for(ll i = 0; i < n; i++)
    {
        cin >> wgt[i];
    }
    ll ans = fun(pro, wgt, w, n) ;
    cout << ans << endl;
    }
}