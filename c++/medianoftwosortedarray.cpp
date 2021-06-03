#include <bits/stdc++.h>
using namespace std;


 //median of single array
float medone(int arr[], int n)
{
   if (n == 0) return -1;
   if (n%2 == 0) return (double)(arr[n/2] + arr[n/2-1])/2;
   else return arr[n/2];
}


//median of two integers
float med2(int a, int b)
{ 
    return ( a + b ) / 2.0; 
}
 
//median of three integers
float med3(int a, int b, int c)
{
    return a + b + c - max(a, max(b, c))- min(a, min(b, c));
}
 
// median of four integers
float med4(int a, int b, int c, int d)
{
    return ( a + b + c + d - max( a, max( b, max( c, d ) ) ) - min( a, min( b, min( c, d ) ) ) ) / 2.0;
}

float findmedian( int A[], int n, int B[], int m )
{
    if (n == 0) return medone(B, m); //First array is empty
    if (n == 1) //First array has one element
    {
        if (m == 1)  return med2(A[0], B[0]); // median of the two elements
        if (m%2!=0) return med2( B[m/2], med3(A[0], B[m/2 - 1], B[m/2 + 1]) ); // Larger array has odd no. of elements
        else return med3( B[m/2], B[m/2 - 1], A[0] ); // Larger array has even no. of elements
    }
    
    else if (n == 2) // First array has two elements
    {
        if (m == 2) return med4(A[0], A[1], B[0], B[1]); // median of all 4 elements
        if (m%2!=0) return med3 ( B[m/2],max(A[0], B[m/2 - 1]),min(A[1], B[m/2 + 1])); // Larger array has odd no. of elements
        else return med4 ( B[m/2],B[m/2 - 1],max( A[0], B[m/2 - 2] ),min( A[1], B[m/2 + 1] )); // Larger array has even no. of elements
    }
 
    int medA = ( n - 1 ) / 2;
    int medB = ( m - 1 ) / 2;
 
    if (A[medA] <= B[medB] ) return findmedian(A + medA, n/2 + 1, B, m - medA ); // Discard elements on left of medA in first array and right of medB in second array
    else return findmedian(A, n/2 + 1, B + medA, m - medA ); // Discard elements on right of medA in first array and left of medB in second array
}
 
int main()
{
    int n,m;
    cout<<"Enter n amd m: ";
    cin>>n>>m;
    int A[n],B[m];
    for(int i=0;i<n;i++) 
        {
            cout<<"Enter A["<<i<<"]: ";
            cin>>A[i];
        }
    for(int i=0;i<m;i++) 
        {
            cout<<"Enter B["<<i<<"]: ";
            cin>>B[i];
        }
    float c;
    if(n<m) c=findmedian( A, n, B, m ); // First array is smaller
    else c=findmedian( B, m, A, n );
    cout<<"median of merged array is: ";
    cout<<c;
    return 0;
}