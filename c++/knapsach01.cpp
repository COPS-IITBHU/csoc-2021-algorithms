#include <bits/stdc++.h>
using namespace std;

int knapSack(int W, int wt[], int val[], int n);

int main()
{
    int n = 3, W = 4;
    int wt[] = {4,5,1};
    int val[] = {1,2,3};
    cout << "The maximum number possible in the knapsach is " << knapSack(W, wt, val, n);
    //expected output is 3
    return 0;
}

int knapSack(int W, int wt[], int val[], int n) 
{ 
    int arr[n+1][W+1];
    memset(arr, -1, sizeof(arr));
    for(int i = 0; i <= n; ++i)
    {
        for(int j = 0; j <= W; ++j)
        {
            if(i == 0 || j == 0)
                arr[i][j] = 0;
        }
    }
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= W; ++j)
        {
            if(wt[i-1] <= j)
            {
                arr[i][j] = max(val[i-1] + arr[i-1][j - wt[i-1]], arr[i-1][j]);
            }
            else
            {
                arr[i][j] = arr[i-1][j];
            }
        }
    }
    return arr[n][W];
}