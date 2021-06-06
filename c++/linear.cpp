#include <iostream>
using namespace std;
int main() {
    
    int n=8;
    int arr[]={1,2,3,4,15,54,25,78};
    
    int x= 15;
    
    for(int i=0;i<n;i++)
    {
        if(x==arr[i])
        {
            cout<<x<<" is present at location "<<(i+1);
            break;
        }
    }
    
    
    return 0;
}
