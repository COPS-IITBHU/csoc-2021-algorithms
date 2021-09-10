#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	set<int> S;
    multiset<int>::iterator it;
    for(auto x:v)
    {
        S.insert(x);
        it = S.upper_bound(x);
        if(it!=S.end()) S.erase(it);
    }
	cout<<S.size()<<"\n";
	return 0;
}