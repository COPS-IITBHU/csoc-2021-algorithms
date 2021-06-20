#include <iostream>
using namespace std;

int main()
{
    int x;
    cin >> x;
    int n=x;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int step = 0; step < (n-1); ++step) {
        for (int i = 0; i < n - (step-1); ++i) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
    cout<<"sorted array:-"<<endl;
    for(int i=0;i<n;i++){
        cout <<arr[i]<<"\t";
    }
}