#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void print_sudoku(int sudoku[9][9])
{
  printf("The Sudoku contains:\n");
  for (int j=0; j<9; j++)
  {
    for (int i=0; i<9;i++)
    {
      printf("%d  ",sudoku[j][i]);
    }
    printf("\n");
  }
}

int check_sudoku(int sudoku[9][9], int row, int column, int number)
{
  /*
   *  This function checks whether a Sudoku is properly
   * solved. That means that each row, column, and
   * 3x3 subgrid uses each digit only once.
   *
   *  If *ignores* zeros, so you can use it to check
   * that a partial solution is valid
   */
  

    int k = 1;

   for(int i = 0; i < 9; i++)
   {
     if(sudoku[row][i] == number)
        k = 0;
   }

   for(int i = 0; i < 9; i++)
   {
     if(sudoku[i][column] == number)
        k = 0;
   }
  
  if(row == 0 || row == 1 || row == 2)
    row = 0;
  if(row == 3 || row == 4 || row == 5)
    row = 3;
  if(row == 6 || row == 7 || row == 8)
    row = 6;

  if(column == 0 || column == 1 || column == 2)
    column = 0;
  if(column == 3 || column == 4 || column == 5)
    column = 3;
  if(column == 6 || column == 7 || column == 8)
    column = 6;

  if(sudoku[row][column] == number)k = 0;
  if(sudoku[row + 1][column] == number)k = 0;
  if(sudoku[row + 2][column] == number)k = 0;
  if(sudoku[row][column + 1] == number)k = 0;
  if(sudoku[row][column + 2] == number)k = 0;
  if(sudoku[row + 1][column + 1] == number)k = 0;
  if(sudoku[row + 2][column + 2] == number)k = 0;
  if(sudoku[row + 2][column + 1] == number)k = 0;
  if(sudoku[row + 1][column + 2] == number)k = 0;

  
 return k;
}

int solved(int sudoku[9][9], int *i, int * j)
{
  /*
   * This function checks whether a given Sudoku is
   * completely solved (it has no zeros, all digits
   * are used once per row, column, and sub-grid.
   * It returns 1 if the Sudoku is solved, zero
   * otherwise
   */
  
 
   for(*i = 0; *i < 9; (*i)++)
   {
     for(*j = 0; *j < 9; (*j)++){
       if(sudoku[*i][*j] == 0){
         return 0;
        }
     }
   }
   return 1;
}


int is_matrix_correct(int sudoku[9][9])
{
  int k = 1;
  for(int row = 0; row < 9; row++)
  {
    for(int column = 0; column < 9; column++)
    {
      if(sudoku[row][column] != 0)
      {
        int number = sudoku[row][column];

        for(int i = 0; i < 9; i++)
        {
            if(i != column && sudoku[row][i] == number)
               k = 0;
        }
        for(int i = 0; i < 9; i++)
        {
            if(i != row && sudoku[i][column] == number)
               k = 0;
        }

        int r;
        int c;
  
      if(row == 0 || row == 1 || row == 2)
          r = 0;
      if(row == 3 || row == 4 || row == 5)
          r = 3;
      if(row == 6 || row == 7 || row == 8)
          r = 6;

      if(column == 0 || column == 1 || column == 2)
          c = 0;
      if(column == 3 || column == 4 || column == 5)
          c = 3;
      if(column == 6 || column == 7 || column == 8)
          c = 6;

  if((r != row || c != column) && sudoku[r][c] == number)k = 0;
  if((r+1 != row || c != column)&& sudoku[r + 1][c] == number)k = 0;
  if((r+2 != row || c != column)&& sudoku[r + 2][c] == number)k = 0;
  if((r != row || c+1 != column)&& sudoku[r][c + 1] == number)k = 0;
  if((r != row || c+2 != column)&& sudoku[r][c + 2] == number)k = 0;
  if((r+1 != row || c+1 != column)&& sudoku[r + 1][c + 1] == number)k = 0;
  if((r+2 != row || c+2 != column)&& sudoku[r + 2][c + 2] == number)k = 0;
  if((r+2 != row || c+1 != column)&& sudoku[r + 2][c + 1] == number)k = 0;
  if((r+1 != row || c+2 != column)&& sudoku[r + 1][c + 2] == number)k = 0;
      }
    }
  }

  return k;
}


int solve_sudoku(int sudoku[9][9], int depth)
{
 
   if(is_matrix_correct(sudoku) == 1)
   {

   int row = 0;
    int col = 0;
    
    if (solved(sudoku, &row, &col)){
        return 1;
    }
    
    for (int num = 1; num <= 9; num++ ) {
        
        if (check_sudoku(sudoku, row, col, num)) {
            sudoku[row][col] = num;
            
            if (solve_sudoku(sudoku, depth + 1)) {
                return 1;
            }
            
            sudoku[row][col] = 0;
        }
    }
    
    return 0;
   }
   else
   {
     return 0;
   }
}


#ifndef __testing

int main()
{

  int Sudoku[9][9]={{5, 3, 0, 0, 7, 0, 0, 0, 0},
         {6, 0, 0, 1, 9, 5, 0, 0, 0},
         {0, 9, 8, 0, 0, 0, 0, 6, 0},
         {8, 0, 0, 0, 6, 0, 0, 0, 3},
         {4, 0, 0, 8, 0, 3, 0, 0, 1},
         {7, 0, 0, 0, 2, 0, 0, 0, 6},
         {0, 6, 0, 0, 0, 0, 2, 8, 0},
         {0, 0, 0, 4, 1, 9, 0, 0, 5},
         {0, 0, 0, 0, 8, 0, 0, 7, 9}};

// int Sudoku[9][9]={{9, 0, 6, 0, 7, 0, 4, 0, 3},
// {0, 0, 0, 4, 0, 0, 2, 0, 0},
// {0, 7, 0, 0, 2, 3, 0, 1, 0},
// {5, 0, 0, 0, 0, 0, 1, 0, 0},
// {0, 4, 0, 2, 0, 8, 0, 6, 0},
// {0, 0, 3, 0, 0, 0, 0, 0, 5},
// {0, 3, 0, 7, 0, 0, 0, 5, 0},
// {0, 0, 7, 0, 0, 5, 0, 0, 0},
// {4, 0, 5, 0, 1, 0, 7, 0, 8}};

  //  int Sudoku[9][9]={{1, 0, 0, 0, 0, 0, 0, 0, 0},
  //                   {0, 0, 0, 0, 0, 0, 0, 0, 0},
  //                   {0, 0, 1, 0, 0, 0, 0, 0, 0},
  //                   {0, 0, 0, 0, 0, 0, 0, 0, 0},
  //                   {0, 0, 0, 0, 0, 0, 0, 0, 0},
  //                   {7, 0, 0, 0, 2, 0, 0, 0, 6},
  //                   {0, 6, 0, 0, 0, 0, 2, 8, 0},
  //                   {0, 0, 0, 4, 1, 9, 0, 0, 5},
  //                   {0, 0, 0, 0, 8, 0, 0, 7, 9}};


  printf("Input puzzle is:\n");
  print_sudoku(Sudoku);
  
  solve_sudoku(Sudoku,0);
  // solve(Sudoku);

  
  printf("Solution is:\n");
  print_sudoku(Sudoku);
  
}

#endif

