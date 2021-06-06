#include <bits/stdc++.h>
using namespace std;
 
int max(int a, int b)
{
    return (a > b) ? a : b;
}

int eggdrop(int n, int f)
{
    
    if (n == 1 || f == 0)
        return f;
 
    if (n == 1)
        return f;
 
    int min = INT_MAX, x, res;
 
    for (x = 1; x <= f; x++) {
        res = max(
            eggdrop(n - 1, x - 1),
            eggdrop(n, f - x));
        if (res < min)
            min = res;
    }
 
    return min + 1;
}
 
int main()
{
    int n = 5, f = 16;
    cout << "Minimum number of trials required for "
         << n << " eggs and " << f
         << " floors is "
         << eggdrop(n, f) << endl;
    return 0;
}