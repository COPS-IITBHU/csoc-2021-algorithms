//Rat in a Maze(solved using backtracking)

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define ull unsigned long long
#define rep(i, m, n) for (auto i = m; i < n; i++)
#define pb push_back
#define MOD 1000000007
#define N 1000

int arr[N][N], solArr[N][N];

//Function to check if rat can enter that cell or not
bool isSafe(int arr[N][N], int x, int y, int n)
{
    if (x < n && y < n && arr[x][y] == 1)
        return true;
    return false;
}

//x and y denote the starting position of the rat, n is size of the square matrix or maze
bool rat_ina_maze(int arr[N][N], int x, int y, int n, int solArr[N][N])
{
    if (x == n - 1 && y == n - 1)
    {
        solArr[x][y] = 1;
        return true;
    }

    if (isSafe(arr, x, y, n))
    {
        solArr[x][y] = 1;
        if (rat_ina_maze(arr, x + 1, y, n, solArr))
            return true;
        else if (rat_ina_maze(arr, x, y + 1, n, solArr))
            return true;

        solArr[x][y] = 0;

        return false;
    }
    return false;
}

void Solve()
{
    int n;
    cin >> n; //Size of the square matrix

    rep(i, 0, n)
    {
        rep(j, 0, n)
        {
            cin >> arr[i][j]; //rat can enter that cell if value is 1 and if it is 0 then can't
            solArr[i][j] = 0;
        }
    }
    cout << endl;

    if (rat_ina_maze(arr, 0, 0, n, solArr))
    {
        rep(i, 0, n)
        {
            rep(j, 0, n) cout << solArr[i][j] << " ";

            cout << endl;
        }
    }
    else
        cout << "No possible solution of this maze!" << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll T = 1;
    cin >> T; //Number of test cases
    while (T--)
        Solve();

    return 0;
}