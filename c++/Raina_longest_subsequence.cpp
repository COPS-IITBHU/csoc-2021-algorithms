#include <iostream>
using namespace std;

int main() {

  string str1, str2;

  cout<<" Enter String 1 : ";
  cin>>str1;
  cout<<" Enter String 2 : ";
  cin>>str2;

  int len1 = str1.length();
  int len2 = str2.length();

  int arr[len1 + 1][len1 + 1];
  int i,j;


   for (i = 0; i <= len1; i++) 
   {
      for (j = 0; j <= len2; j++) 
    {
      if (i == 0 || j == 0)
        arr[i][j] = 0;
      else if (str1[i - 1] == str2[j - 1])
        arr[i][j] = arr[i - 1][j - 1] + 1;
      else
        arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
    }
  }

  int val = arr[len1][len2];
  char lcs[val + 1];
  lcs[val] = '\0';

  i = len1;
  j = len2;
  while (i > 0 && j > 0) 
  {
    if (str1[i - 1] == str2[j - 1]) 
    {
      lcs[val - 1] = str1[i - 1];
      i--;
      j--;
      val--;
    }

    else if (arr[i - 1][j] > arr[i][j - 1])
      i--;
    else
      j--;
  }
  
   cout <<"\n Longest Common Subsequence : " << lcs <<"\n";
  
  
}