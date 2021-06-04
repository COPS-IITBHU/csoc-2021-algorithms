#include <bits/stdc++.h>
using namespace std;
int longestCommonSubsequence(string &st1, string &st2)
{
    int n = st1.size();
    int m = st2.size();
    int arr[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                arr[i][j] = 0;
            else if (st1[i - 1] == st2[j - 1])
                arr[i][j] = 1 + arr[i - 1][j - 1];
            else
                arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
        }
    }
    return arr[n][m];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string word1, word2;
    cin >> word1 >> word2;
    cout << longestCommonSubsequence(word1, word2);
    return 0;
}