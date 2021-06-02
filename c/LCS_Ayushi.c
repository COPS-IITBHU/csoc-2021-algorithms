// LONGEST COMMON SUBSEQUENCE 
//Language used : C
//Ayushi Gupta 



#include <stdio.h>
#include <string.h>

int main() 
{
    int x, y, l1, l2, arr[20][20];
    char Seq1[20], Seq2[20], b[20][20];

    printf("Enter sequence 1:\n");
    scanf("%s",Seq1);

    printf("Enter sequence 2:\n");
    scanf("%s",Seq2);

  // Lengths of sequences
   l1 = strlen(Seq1);
   l2 = strlen(Seq2);

  // 0 matrix
  for (x = 0; x <= l1; x++){
    arr[x][0] = 0;}
    
  for (x = 0; x <= l2; x++){
    arr[0][x] = 0;}
    
    

  
  for (x = 1; x <= l1; x++)
    for (y = 1; y <= l2; y++) {
        
      if (Seq1[x - 1] == Seq2[y - 1]) {
        arr[x][y] = arr[x - 1][y - 1] + 1;
      } 
      else if (arr[x - 1][y] >= arr[x][y - 1]) {
        arr[x][y] = arr[x - 1][y];
      }
      else {
        arr[x][y] = arr[x][y - 1];
      }
    }
    

  int i = arr[l1][l2];
  char lcs[i + 1];
  lcs[i] = '\0';
  int k = l1, l = l2;
  
  while (k > 0 && l > 0) {
    if (Seq1[k - 1] == Seq2[l - 1]) {
      lcs[i - 1] = Seq1[k - 1];
      k--;
      l--;
      i--;
    }

    else if (arr[k - 1][l] > arr[k][l - 1])
      k--;
    else
      l--;
  }

 
  printf("Seq1 : %s \nSeq2 : %s \n", Seq1, Seq2);
  printf("Longest Common Subsequence: %s", lcs);

  return 0;
}