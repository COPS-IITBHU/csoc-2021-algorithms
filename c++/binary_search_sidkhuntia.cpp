

int binarySearch(int arr[], int l, int r, int x);


int main()
{
    int n;
    cout<<"Enter the number of elements"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elemets: "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the number to search"<<endl;
    int x;
    cin>>x;
  

    int result = binarySearch(arr,0, n-1, x);
    (result == -1)
        ? cout << "Not available"
        : cout << "Position: " << result+1;
    return 0;
}

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
