// Algorithm for finding the GCD of two numbers also known as Euclid's Algorithm to find the GCD of the numbers

#include <bits/stdc++.h>
using namespace std;
 
int gcd(int a, int b)      // Recursive function
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
     
}
  
// Main starts here 
int main()
{
    int a, b;
    cin>>a>>b;
    cout<<"GCD of "<<a<<" and "<<b<<" is : "<<gcd(a, b);
    return 0;
}