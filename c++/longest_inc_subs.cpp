#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n; // input the size of array
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i]; // input the array
	}
	int vals[n]; // length of incr subsequence upto i-th index
	for (int i = 0; i < n; ++i)
	{
	 	vals[i]=1; // initialising all with 1(itself).
	}
	for (int i = 1; i < n; ++i)
	{
	 	for (int j = 0; j < i; ++j) // traversing for index-j less than index-i
	 	{
	 		if (a[i]>a[j] && vals[i]<vals[j]+1) //if any subs is longer or equal and  value too is smaller than the value at index-i.
	 		{
	 			vals[i]=vals[j]+1; // update the value of subsequence upto i.
	 		}
	 	}
	}
	int max=1;
	for (int i = 0; i < n; ++i)
	{
		if (vals[i]>max)
		{
			max=vals[i];
		}
	} 
	cout<<max<<endl;
	return 0;
}
