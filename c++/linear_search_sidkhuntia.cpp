#include <iostream> 

#define lli long long int
#define li long int
#define ld long double
#define f(i, n) for (int i; i < n; i++)

using namespace std;
const lli mod = 1e9 + 7;

int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int arr[] = {1, 2, 3, 4, 5};
    int x = 3;
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = search(arr, n, x);
    (result == -1)
        ? cout << "Not available"
        : cout << "Position: " << result+1;
    return 0;
}