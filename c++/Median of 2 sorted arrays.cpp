#include
using namespace std;

int Med(int ar1[], int ar2[], int n, int m)
{
int i = 0;
int j = 0;
int c;
int m1 = -1, m2 = -1;

if((m + n) % 2 == 1) {
for (c = 0; c <= (n + m)/2; c++) {
if(i != n && j != m){
m1 = (ar1[i] > ar2[j]) ? ar2[j++] : ar1[i++];
}
else if(i < n){
m1 = ar1[i++];
}
else{
m1 = ar1[j++];
}
}
return m1;
}

else {
for (c = 0; c <= (n + m)/2; c++) {
m2 = m1;
if(i != n && j != m){
m1 = (ar1[i] > ar2[j]) ? ar2[j++] : ar1[i++];
}
else if(i < n){
m1 = ar1[i++];
}
else{
m1 = ar1[j++];
}
}
return (m1 + m2)/2;
}
}

int main()
{
int m,n,i;
cout << "\nEnter the size of array 1 : ";
cin >> m;
cout << "\nEnter the size of array 2 : ";
cin >> n;
int ar1[m];
int ar2[n];

cout << "\nInput the array 1 elements : ";
for(i = 0; i < m; i++)
cin >> ar1[i];

cout << "\nInput the array 2 elements : ";
for(i = 0; i < n; i++)
cin >> ar2[i];

cout << "\nMedian of two arrays : ";
cout << Med(ar1, ar2, m, n);
cout << endl;
return 0;
}

