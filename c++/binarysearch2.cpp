#include <iostream>
using namespace std;

int binarySearch(int arr[], int l , int r, int num);

int main()
{
    int n, num;
    cin >> n >> num;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int index = binarySearch(arr, 0, n - 1, num);
    if (index == -1)
    {
        cout << num << " is not present in the given array";
    }

    else
    {
        cout << num << " is present at index " << index + 1 << " in the array";
    }

    return 0;
}
int binarySearch(int arr[], int l, int r, int num)
{
    if (l <= r)
    {
        int mid = l + (r-1)/2;
        if (arr[mid] == num)
        {
            return mid;
        }

        if (arr[mid] > num)
        {
            return binarySearch(arr, l, mid - 1, num);
        }

        if (arr[mid] < num)
        {
            return binarySearch(arr, mid + 1, r, num);
        }
    }
    return -1;
}
