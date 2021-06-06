/******************************************************************************
n queen problem 
*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

int sum=0;  //total number of solutions

void search(int i,int n,int v[],int column[],int diag1[],int diag2[])
{ //if all queens placed
  if(i==n)
  { sum++;

    //printing the solution
    cout<<"\n\n";
    for(int x=0;x<n;x++)
    {  for(int y=0;y<n;y++)
       { if(v[x]==y+1)
         { cout<<"Q";}
         else
         { cout<<".";}
       }
       cout<<"\n";
    }
    return;
  }

  //else
  for(int j=0;j<n;j++)
  { 
    if(column[j]|diag1[i+j]||diag2[j-i+n-1]) 
        continue;  //if queens can't be placed

    column[j]=diag1[i+j]=diag2[j-i+n-1]=1;  //else place queen
    v[i]=j+1;

    search(i+1,n,v,column,diag1,diag2);  //move to next row

    column[j]=diag1[i+j]=diag2[j-i+n-1]=0;  //backtrack
    v[i]=0;
  }
}

int main()
{   int n;
    cout<<"For nxn chessboard, enter n: ";
    cin>>n;
    int v[n];
    int column[n]={0},diag1[2*n-1]={0},diag2[2*n-1]={0};

    search(0,n,v,column,diag1,diag2);

    if(sum==0) cout<<"\nNO SOLUTION EXISTS\n";
    else cout<<"\nTotal number of solutions = "<<sum<<"\n"; 

    return 0;
}
