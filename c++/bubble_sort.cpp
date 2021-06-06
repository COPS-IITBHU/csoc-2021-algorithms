#include <iostream>
using namespace std;

void bubble_sort(int n, int arr[]){
    int is_sorted = 0;
    for(int j = 0; j<n-1; j++){
        is_sorted=1;
        for(int i = 0; i<n-1-j; i++){
            int key = arr[i+1];
                if(arr[i]>arr[i+1]){
                arr[i+1]= arr[i];
                arr[i]= key;
                is_sorted=0;
        }
    }
    if(is_sorted){
        return;
    }
    }
    
}
void create(int n, int arr[]){
    for(int i=0; i<n; i++){
        cout<<"Enter the value at "<<i<<"th index: ";
        cin>>arr[i];
    }
}
void display(int n, int arr[]){
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int n;
    int arr[n];
    cout<<"Enter the size of the array \n";
    cin>>n;
    create(n, arr);
    display(n, arr);
    bubble_sort(n, arr);
    cout<<endl;
    display(n, arr);
    return 0;
}

