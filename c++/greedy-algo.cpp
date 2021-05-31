#include <bits/stdc++.h>
using namespace std;

void activityselection(int a[], int b[], int n)
{
    int i=0;
    cout <<"The index of the activities are: "<< i;
    for (int j = 1; j < n; j++)
    {
      if (a[j] >= b[i])
      {
          cout <<" "<< j;
          i = j;
      }
    }
}