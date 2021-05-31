#include <iostream> 

#define lli long long int
#define li long int
#define ld long double
#define f(i, n) for (int i; i < n; i++)

using namespace std;
const lli mod = 1e9 + 7;

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int m = l + (r - l) / 2;
 
        if (arr[m] == x)
            return m;
 

        if (arr[m] > x)
            return binarySearch(arr, l, m - 1, x);
 

        return binarySearch(arr, m + 1, r, x);
    }
 
    return -1;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int arr[] = {1, 2, 3, 4, 5};
    int x = 3;
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = binarySearch(arr,0, n-1, x);
    (result == -1)
        ? cout << "Not available"
        : cout << "Position: " << result+1;
    return 0;
}