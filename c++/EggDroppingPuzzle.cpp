#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> memo(MAX, vector<int> (MAX, -1)); 
int egg_puzzle(int n, int k) {

	if(memo[n][k] != -1) {return memo[n][k];} 
	
	if (k == 1 || k == 0) return k; 

	if (n == 1) return k; 

	int min = INT_MAX, x, res;

	for (x = 1; x <= k; x++) {
        // If egg breaks due to the fall from 'x'th floor, 
        //'x-1' floors need to be checked with 'n-1' eggs.

        // If egg survives the fall from 'x'th floor,
        //'k-x' floors need to be checked with 'n' eggs.

        // For the worst case, we take the maximum of both the cases. 
        res = max(egg_puzzle(n - 1, x - 1), egg_puzzle(n, k - x));
    	if (res < min) min = res;
	}
	
	memo[n][k] = min+1;
	return min + 1;
}

int main() {

	int n = 2, k = 36; // No. of eggs (n) = 2, No. of floors (k) = 36.
	cout<<"Minimum number of trials in worst case with "<<n<<" eggs and "<<k<<" floors is "<<egg_puzzle(n, k)<<endl;
	return 0;
}
