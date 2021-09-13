#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
const ll MOD=1e9+7;



void solve()
{
    fast;
    ll n,sz = 0;
    cin >> n;
    vector<ll> a(n,0),b(n,0);
    for(int i=0;i<n;i++)  cin >> a.at(i);
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a.at(j)>a.at(i) && b.at(i)+1>b.at(j))
            {
                b.at(j) = b.at(i) + 1;
                sz = max(sz,b.at(j));
            }
        }
    }
    cout << sz + 1 << endl;
}


int main()
{
  fast;
 
    solve();
  
  return 0;
}