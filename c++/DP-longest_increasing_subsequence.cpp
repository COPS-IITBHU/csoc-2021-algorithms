//Algorithm for finding length longest increaing subsequence

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <assert.h>
#include <ctime>
#include <bitset>
#include <numeric>
#include <complex>
#include <valarray>
#include<climits>
using namespace std;
typedef long long int z;

//function LIS() returns the length of longest increasing subsequece in arr[] of size n
z LIS(z n, z arr[])     
{
    z d[n+1],res=0; //here d[] is the DP array
    d[0]=INT_MIN;
    for(z i=1;i<n+1;i++)
    {
        d[i]=INT_MAX;
    } 
    for(z i=0;i<n;i++)  
    {
       z a=upper_bound(d,d+n+1,arr[i])-d;   
       if(arr[i]<d[a]&&arr[i]>d[a-1])
       {
           d[a]=arr[i];
       }
    }
    for(z i=n;i>0;i--)  //Searching for max index not having value equals to INT_MAX
    {
        if(d[i]!=INT_MAX)
        {
            res=i;
            break;
        }
    }
    return res; //res is length of LIS of the given array
}

//main starts here
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
    
    z n;
    cin>>n;
    z arr[n];
    for(z i=0;i<n;i++)  
    {
        cin>>arr[i];
    }
    cout<<LIS(n,arr)<<endl;
    return 0;
}