//Somos insignificantes. Por mais que você programe sua vida, a qualquer momento tudo pode mudar.
// If you have God on your side,everything becomes clear

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAX_N = 1e5 + 5;
const int MAX_L = 20; // ~ Log N
const long long MOD = 1e9 + 7;
const long long INF = 1e9 + 7;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
#define fi first
#define popcount(x) __builtin_popcountll(x)
#define se second
#define LSOne(S) (S & (-S))
#define isBitSet(S, i) ((S >> i) & 1)
/*void Sieve(int n) 
{ 
    
    //bool prime[n+1]; 
    //memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    
} */
/* struct cmp{
    bool operator()(const pair<int,int>& v1,const pair<int,int>& v2) const{
    	
    }};*/
 long long binpow(long long a, long long b) {
    a %=MOD;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    res=res%MOD;
    return res;
}
const int MAXN=100001;
vector<vector<int>> adj, adj_rev;
vector<bool> used;
vector<int> order, component;
int n;
void dfs1(int v) {
    used[v] = true;

    for (auto u : adj[v])
        if (!used[u])
            dfs1(u);

    order.push_back(v);
}

void dfs2(int v) {
    used[v] = true;
    component.push_back(v);

    for (auto u : adj_rev[v])
        if (!used[u])
            dfs2(u);
}




void solve() {
    cin>>n;
    int m;
    cin>>m;
    adj.resize(n+1);
    adj_rev.resize(n+1);
    while(m--){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj_rev[v].push_back(u);
    }
    used.assign(n+1, false);

    for (int i = 1; i <= n; i++)
        if (!used[i])dfs1(i);

    reverse(order.begin(), order.end());
    used.assign(n+1, false);
    int cnt=1;
    for (auto v : order){
        if (!used[v]) {dfs2 (v);
        //Print Component
        cout<<"Component : "<<cnt<<endl;
        for(auto&j:component)cout<<j<<" ";
        cout<<endl;
        component.clear();
        cnt++;    
        } 
    }

   
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int tc=1;// cin >> tc;
    for (int t = 1; t <= tc; t++) {
        //cout << "Case #" << t  << ": ";
        solve();
    }
}