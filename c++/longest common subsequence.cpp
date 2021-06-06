
#include<bits/stdc++.h> 
using namespace std; 



/* Returns length of longest common subsequence for X[0..m-1], Y[0..n-1] */
int longestcs( char *X, char *Y, int m, int n ) 
{ 
	int arr[m + 1][n + 1]; 
	int i, j; 
	

	for (i = 0; i <= m; i++) 
	{ 
		for (j = 0; j <= n; j++) 
		{ 
		if (i == 0 || j == 0) 
			arr[i][j] = 0; 
	
		else if (X[i - 1] == Y[j - 1]) 
			arr[i][j] = arr[i - 1][j - 1] + 1; 
	
		else
			arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]); 
		} 
	} 
		
	/* arr[m][n] contains length of Longest Common Subsequence 
	for X[0..n-1] and Y[0..m-1] */
	return arr[m][n]; 
} 



int main() 
{ 
	
	int m,n;
	cout<<"Enter number of elements in arrays: ";
	cin>>m>>n;
	char X[m]; 
	char Y[n];
	for(int i=0;i<m;i++)
	{
		cin>>X[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>Y[i];
	}
         
	
	cout << "Length of lonest common subsequence is "
		<< longestcs( X, Y, m, n ); 
	
	return 0; 
} 

