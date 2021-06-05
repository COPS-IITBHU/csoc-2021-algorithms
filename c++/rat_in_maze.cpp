#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool gotoCell(int** a, ll n, ll x, ll y)
{
    if (x<n && y<n && a[x][y]==1)
    {
        return 1;
    }
    return 0;
}

bool ratMaze(int** a, ll n, ll x, ll y, int** solArr)
{
    if(x==(n-1) && y==(n-1))
    {
        solArr[x][y]=1;
        return 1;
    }
    if(gotoCell(a,n,x,y))
    {
        solArr[x][y]=1;
        if(ratMaze(a,n,x+1,y,solArr))
        {
            return 1;
        }
        if(ratMaze(a,n,x,y+1,solArr))
        {
            return 1;
        }
        solArr[x][y]=0;
        return 0;
        
    }
    return 0;
}

int32_t main()
{
    ll n;cin>>n;
    int** a = new int*[n];
    for (ll i=0;i<n;i++)
    {
        a[i] = new int[n];
    }
    int** solArr = new int*[n];
    for (ll i=0;i<n;i++)
    {
        solArr[i] = new int[n];
    }
    for (ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
        {
            cin>>a[i][j];
            solArr[i][j]=0;
        }
    }
    // if(ratMaze(a,n,0,0,solArr))
    // {
    //     for (ll i=0;i<n;i++)
    //     {
    //         for(ll j=0;j<n;j++)
    //         {
    //             cout<<solArr[i][j]<<" ";
    //         }
    //         cout<<endl;
    //     }
    // }
    
    cout<<ratMaze(a,n,0,0,solArr);

}