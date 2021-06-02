#include <bits/stdc++.h>

using namespace std;

int longestIncreasingSubsequence(int arr[], int n);

int main()
{
    int n;
    cin >> n;  // Enter length of the array

    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];  // Enter Array Elements
    }

    cout << longestIncreasingSubsequence(arr, n) << endl;
}

int longestIncreasingSubsequence(int arr[], int n)
{
    int c[n + 1];
    for (int i = 1; i < n + 1; ++i)
    {
        c[i] = INT_MAX;
    }
    c[0] = INT_MIN;
    for (int i = 0; i < n; ++i)
    {
        int j = upper_bound(c, c + n, arr[i]) - c;
        if (c[j - 1] < arr[i] && arr[i] < c[j])
        {
            c[j] = arr[i];
        }
    }

    int ans;
    for (int i = 0; i < n + 1; ++i)
    {
        if (c[i] < INT_MAX)
        {
            ans = i;
        }
    }
    return ans;
}
