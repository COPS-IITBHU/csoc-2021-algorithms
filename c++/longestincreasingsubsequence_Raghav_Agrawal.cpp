#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef vector<int> vi;

typedef vector<ll> vl;
typedef vector<str> vs;
typedef vector<vector <int> > vvi;
 
const ll remi=1000000007;
const ll remi2=998244353;
const ll inf=1e18+1e17+1e16;
 
#define pi 3.141592653589
#define pb push_back
#define pf push_front
#define F first
#define S second
#define el "\n"
#define sp " "
int l_i_s(vi v);
int main(){ 
   int n;
   cin >> n;
   vi v;
   int ele;
   for (int i = 0; i < n; ++i)
      {
          cin >> ele ;
          v.pb(ele);
      }   
   int count = l_i_s(v);
  cout << count ;
    return 0;
}


int l_i_s(vi v){

   vi lis(v.size(),1);
   int i,j;
   for ( i = 1; i < v.size(); ++i)
   {
       for (j = 0; j < v.size(); ++j)
       {
           if(v[i] > v[j] && lis[i] < lis[j] + 1) 
                lis[i] = lis[j] + 1; 
       }
   }


   return *max_element(lis.begin(),lis.end()) ;




}