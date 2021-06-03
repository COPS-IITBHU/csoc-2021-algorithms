#include <bits/stdc++.h>
using namespace std;
int longestPalindromicSubseq(char *seq)
{
    int l = strlen(seq);
    int track[l][l] = {0}; // to keep the track of length of palindromic subsequence
    int i, j, terms = 1;
    while (terms <= l)
    {
        for (i = 0; i < l - terms + 1; i++)
        {
            j = i + terms - 1;
            // subsequence of a single character is always palindrome
            if (seq[i] == seq[j] && terms == 1)
                track[i][j] = 1;
            // subsequence of two same characters is always palindrome
            else if (seq[i] == seq[j] && terms == 2)
                track[i][j] = 2;
            // when the first and last charcater are same then the length
            // of palindrome is 2 + length of its largest palindromic subsequence
            else if (seq[i] == seq[j])
                track[i][j] = track[i + 1][j - 1] + 2;
            // when the first and last character are not same then the length
            // of palindrome is length of its largest palindromic subsequence
            else
            {
                if (track[i][j - 1] > track[i + 1][j])
                    track[i][j] = track[i][j - 1];
                else
                    track[i][j] = track[i + 1][j];
            }
        }

        terms++;
    }
    return track[0][l - 1];
}

int main()
{
    char inputSequence[] = "ABCBACBA"; // Enter the sequence here!
    int maxlensubseq = longestPalindromicSubseq(inputSequence);
    cout << "Length of maximum palindromic subsequence = " << maxlensubseq << endl;
}