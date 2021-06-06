#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i) cin>>a[i];
    int b[n]={},m=0;
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            if(a[j]>a[i]&&b[i]+1>b[j])
            {
                b[j]=b[i]+1;
                m=max(m,b[j]);
            }
        }
    }
    cout<<m+1;
    return 0;
}