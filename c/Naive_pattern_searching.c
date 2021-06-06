#include <stdio.h>
#include <string.h>


void n_search(char* pattern, char* txt)
{
    int M = strlen(pattern);
    int N = strlen(txt);
 
    for (int i = 0; i <= N - M; i++) {           //Slides pattern[] one by one
        int j;
 
        for (j = 0; j < M; j++)                  //Checks for pattern
            if (txt[i + j] != pattern[j])
                break;
 
        if (j == M)          
            printf("Pattern is at index %d \n", i);
    }
}
 

int main()
{
    char txt[] = "nomemestodayonlypain";
    char pattern[] = "me";
    n_search(pattern, txt);
    return 0;
}