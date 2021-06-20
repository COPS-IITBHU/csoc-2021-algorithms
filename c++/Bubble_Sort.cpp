#include <iostream>
using namespace std;

int main() {
    
    int i,j,a[1000],n;
    cin>>n;
    
    for (i=0;i<=n-1;i++){
       cin>>a[i];
    }
      for (i=0;i<n-1;i++){
         for(j=0;j<n-1-i;j++){
             if(a[j]>a[j+1]){
                 swap(a[j],a[j+1]);
             }
         }
      }
      
      for (i=0;i<=n-1;i++){
       cout<<a[i]<<" ";
    }
    
    
  return 0;
}