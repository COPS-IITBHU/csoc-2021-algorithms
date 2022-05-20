//algorithm for LONGEST COMMON SUBSEQUENCE in C language
//Debarati Bandopadhayay

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    char s1[100], s2[100];
    int len1, len2, i, j, array[100][100];

    //taking input for sequences as strings
    printf("Enter the Sequence 1 :  ");
    scanf("%s", s1);
    printf("Enter the Sequence 2 :  ");
    scanf("%s", s2);

    //calculating length of both the sequences
    len1 = strlen(s1);
    len2 = strlen(s2);

    //creating zero matrices to store values in it later
    for (i = 0; i <= len1; i++)
    {
        array[i][0] = 0;
    }
    for (i = 0; i <= len2; i++)
    {
        array[0][i] = 0;
    }

    //filling elements in the above matrices according to rules of the largest subsequence
    for (i = 1; i <= len1; i++)
    {
        for (j = 1; j <= len2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                array[i][j] = array[i-1][j-1] + 1;
            }
            else if (array[i - 1][j] >= array[i][j - 1])
            {
                array[i][j] = array[i - 1][j];
            }
            else
            {
                array[i][j] = array[i][j - 1];
            }
        }
    }

    //storing the final elements to make the longest common subsequence array
    int m = array[len1][len2];
    char sub[m + 1];

    sub[m] = '\0';
    int a = len1;
    int b = len2;

    while (a > 0 && b > 0)
    {
        if (s1[a - 1] == s2[b - 1])
        {
            sub[m - 1] = s1[a - 1];
            a--;
            b--;
            m--;
        }

        else if (array[a - 1][b] > array[a][b - 1])
        {
            a--;
        }

        else
        {
            b--;
        }
    }

    //final output
    printf("Longest coomon subsequence of %s and %s is :  %s ", s1,s2,sub);

    return 0;
}
