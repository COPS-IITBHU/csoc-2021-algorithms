#include<bits/stdc++.h>
using namespace std;

bool compare1(int a, int b){

    return a < b;
}

bool compare2(int a, int b){

    return  a > b;
}
int main(){
    int i,j,n;
    cin>>n;

    int a[n];

     for(i=0;i<=n-1;i++){
      cin>>a[i];
  }

  sort( a , a+n );

    for(i=0;i<=n-1;i++){
      cout<<a[i]<<" ";
  }
  cout<<endl;

  sort(a, a+n, compare1);

    for(i=0;i<=n-1;i++){
      cout<<a[i]<<" ";
  }
    cout<<endl;

  sort(a, a+n, compare2);

  for(i=0;i<=n-1;i++){
      cout<<a[i]<<" ";
  }
}