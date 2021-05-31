#include <bits/stdc++.h>
using namespace std;

void bubblesort(int a[], int asize) {
    int n = asize;

    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                int x = *(&a[j]);
                *(&a[j]) = *(&a[j+1]);
                *(&a[j+1])=x;
            }
        }
    }
}