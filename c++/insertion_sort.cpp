#include<iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int a[n];
  for(int i=0;i<n;i++)
  {
     cin >> a[i];
  }
   for(int j=1;j<n;j++)
   {
     int current=a[j];
     for(int k=j-1;k>=0;k--)
     {
       if(current<a[k])
       {
         a[k+1]=a[k];
         a[k]=current;
       }
     }
   }
   for(int i=0;i<n;i++)
   {
    cout << a[i] <<" ";
   }
    return 0;
}
