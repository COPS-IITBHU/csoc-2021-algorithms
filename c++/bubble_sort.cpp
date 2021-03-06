#include <iostream>
using namespace std;

void bubbleSort(int arr[], int s);

int main()
{
    int a[] = {-2, 45, 0, 11, -9, 647, 6, -15, 0, 5};
    int n = sizeof(a) / sizeof(a[0]);
    bubbleSort(a, n);
    cout << "Sorted Array in Ascending Order:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "  " << a[i];
    }
    return 0;
}

void bubbleSort(int arr[], int s)
{
    for (int step = 0; step < (s - 1); ++step)
    {
        for (int i = 0; i < s - step - 1; ++i)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
}