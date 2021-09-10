#include<bits/stdc++.h>
using namespace std;
 
#define int         long long
#define double      long double
#define pb          push_back
#define mp			make_pair
#define eb          emplace_back
#define ppi         pair<int,int>
#define fast        ios::sync_with_stdio(NULL),cin.tie(NULL),cout.tie(NULL)
#define input       freopen("input.txt","r",stdin),freopen("output.txt","w",stdout)
#define rep(i,j,n)  for(int i=j;i<n;i++)
#define SET(n)      cout<<fixed<<setprecision(n)
#define INF         1000000000000000000
#define M           1000000007
void solve(){
    vector<int> v;
    int n;
    cin>>n;
    rep(i,0,n){
        int a;
        cin>>a;
        v.pb(a);
    }
    int lis[n];

    lis[0]=1;
  for (int i = 1; i < n; i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
            if (v[i] > v[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
    }
    sort(lis,lis+n);
    cout<<lis[n-1];

}
signed main(){
	fast;
	solve();
	return 0;
}