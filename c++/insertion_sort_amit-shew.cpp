//by amit-shew
#include <bits/stdc++.h>
using namespace std;
void insertionSort(int arr[], int n) {
  for (int i = 1; i<n; i++) {
    int key = arr[i];
    int j = i - 1;
    while (key < arr[j] and j >= 0) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}
int main() {
  int n;
  cout<<"enter size of the array"<<endl;
  cin>>n;
  int a[n];
  cout<<"enter integral elements for the array"<<endl;
  for(int i=0; i<n; i++){
  	cin>>a[i];
  }
  insertionSort(a,n);
  cout << "Sorted array in ascending order:\n";
  for(int i=0; i<n; i++){
  	cout<<a[i]<<", ";
  }
  
  return 0;
}
