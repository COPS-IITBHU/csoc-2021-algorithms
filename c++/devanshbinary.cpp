#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    printf("Enter size of array \n");
    scanf("%d",&n);
    vector<int> v(n);
    printf("Enter elements of array \n");
    for( auto i=0;i<n;i++)
    cin>>v[i];
    int key;
    printf("Enter the key to be searched \n");
    scanf("%d",&key);
    int l=0;//lower index of array
    int u=n-1;//upper index of array
    int mid,f=0;
    while(l<=u)
    {
        mid=l+(u-l)/2;
        if(v[mid]==key)
        {
            cout<<key<<" found at index:"<<mid<<endl;
            f=1;
            break;
        }
        else if(v[mid]<key)
        l=mid+1;
        else
        u=mid-1;
    }
    if(f==0)
    cout<<key<<" not found"<<endl;
    return 0;
}