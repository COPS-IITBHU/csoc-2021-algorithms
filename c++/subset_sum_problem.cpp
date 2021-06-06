#include <iostream>
#include <vector>
using namespace std;

bool subset(vector<int> a, int sum, int n)
{
    vector<vector<bool>> res(n + 1, vector<bool>(sum + 1));
    //res[i][j] is true if there is a subset in vector a before index i whose sum is j
    for (int i = 0; i <= n; i++)
        res[i][0] = true;
    for (int j = 1; j <= sum; j++)
        res[0][j] = false;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= sum; j++)
        {
            if (a[i - 1] > j)
                res[i][j] = res[i - 1][j];
            else
                res[i][j] = res[i - 1][j] | res[i - 1][j - a[i - 1]];
        }

    return res[n][sum];
}

int main()
{
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    int sum;
    cin >> sum;
    if (subset(a,sum,n))
    {
        cout << "Yes,we have a subset in this array whose sum is " << sum << "\n";
    }
    else
    {
        cout << "Sorry ! there doesn't exist any subset whose sum is " << sum << "\n";
    }
    return 0;
}