#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(NULL);cout.tie(NULL);

void pigeonsort(int arr, int n){
int min= *min_element(arr,arr+n);
int max=*max_element(arr,arr+n);
int range= max-min+1;
vector <int> v;
for (int i = 0; i < n; i++)
        v[arr[i] - min].push_back(arr[i]);

        int t=0;
        for (int i = 0; i < range; i++) {
        vector<int>::iterator it;
        for (it = v[i].begin(); it != v[i].end(); ++it)
            arr[index++] = *it;
    }


for(int i=0;i<n;i++){cout<<arr[i];}




}





int main(){
fast
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}
pigeonsort(arr,n);


    return 0;
}