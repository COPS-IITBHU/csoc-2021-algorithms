#include <bits/stdc++.h>
using namespace std;

//The function for returning LIS(longest increasing subsequence):
int lis(int arr[], int n)
{
	int ans[n];
	ans[0] = 1;

	// To compute LIS values in bottom up manner:
	for (int i=1; i<n; i++) {
		ans[i] = 1;
		for (int j=0; j<i; j++)
			if (arr[i]>arr[j] && ans[i]<=ans[j])
				ans[i] = ans[j] + 1;
	}

	return *max_element(ans, ans+n);//returns the maximum value from lis array
}


int main()
{
	int n;
	cout<<"Enter the number of elements:";
	cin>>n;
	cout<<"Enter the elements:";
	int arr[n];

	for(int i=0;i<n;i++)
		cin>>arr[i];

	cout<<"Length of the longest increasing subsequence is: "<<lis(arr, n);

	return 0;
}