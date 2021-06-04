#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int longestPalindromicSubsequence(string s)
{
   int n = s.length();
   int i, j, hd;
   int L[n][n];

   for (i = 0; i < n; i++)
   {
      L[i][i] = 1;
   }
   for (hd = 2; hd <= n; hd++)
   {
      for (i = 0; i < n - hd + 1; i++)
      {
         j = i + hd - 1;
         if (s[i] == s[j] && hd == 2)
         {
            L[i][j] = 2;
         }
         else if (s[i] == s[j])
         {
            L[i][j] = L[i + 1][j - 1] + 2;
         }
         else
         {
            L[i][j] = max(L[i][j - 1], L[i + 1][j]);
         }
      }
   }
   return L[0][n - 1];
}

int main()
{
   string inPuttedString;
   cout << "Enter a string" << endl;
   cin >> inPuttedString;
   int n = inPuttedString.length();
   cout << "The length of the Longest Palindromic Subsequence is " << longestPalindromicSubsequence(inPuttedString);
   return 0;
}