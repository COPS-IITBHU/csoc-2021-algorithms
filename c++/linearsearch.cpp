#include <iostream>

using namespace std;

int linearsearch(int arr[], int n, int element);

int main()
{
    int arr[] = {-1, -4, 233, 578, -14, -2, 22, 23};
    int n = sizeof(arr)/sizeof(arr[0]);
    int index = linearsearch(arr, n, -14);
    if(index == -1) 
        cout << "Element not found in the given array!";
    else
        cout << "The sorted array is : " << index;
    return 0;
}

int linearsearch(int arr[], int n, int element)
{
    int index = -1;
    for(int i = 0; i < n; ++i)
    {
        if(arr[i] == element)
        {
            index = i;
            break;
        }
    }
    return index;
}