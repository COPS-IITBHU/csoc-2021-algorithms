//THIS IS not from cb ....from jennys lecture 

#include <iostream>
using namespace std;

int main() {
  int i, j,n,temp;
  cin>>n;
  int a[n];
  
  for(i=0;i<=n-1;i++){
      cin>>a[i];
  }

  for(i=1;i<=n-1;i++){
        temp = a[i];
        j = i-1;
        while(j>=0 && a[j]>temp){

            a[j+1] = a[j];
            j-- ;
        }

        a[j+1] = temp;
    }

  for(i=0;i<=n-1;i++){
      cout<<a[i]<<" ";
  }
  
  
  return 0;
}