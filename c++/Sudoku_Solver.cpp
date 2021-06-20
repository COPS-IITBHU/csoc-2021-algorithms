   // Solving sudoku using Backtracking

#include <bits/stdc++.h>
using namespace std;

bool Any_Unassigned_Location(int grid[9][9], int& row, int& col)
{
    for (row = 0; row < 9; row++)
        for (col = 0; col < 9; col++)
            if (grid[row][col] == 0)
                return true;
    return false;
}

bool if_UsedInRow(int grid[9][9], int row, int num)
{
    for (int col = 0; col < 9; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}
 
bool if_UsedInCol(int grid[9][9], int col, int num)
{
    for (int row = 0; row < 9; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}
 
bool if_UsedInBox(int grid[9][9], int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row + boxStartRow][col + boxStartCol] == num)
                return true;
    return false;
}

bool isSafe(int grid[9][9], int row, int col, int num)
{
    return !if_UsedInRow(grid, row, num)
           && !if_UsedInCol(grid, col, num)
           && !if_UsedInBox(grid, row - row % 3,
                         col - col % 3, num)
           && grid[row][col] == 0;
}

bool SolveSudoku(int grid[9][9])
{
    int row, col;
 
    if (!Any_Unassigned_Location(grid, row, col))
        return true;
 
    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(grid, row, col, num))
        {     
            grid[row][col] = num;
            if (SolveSudoku(grid))
                return true;
            grid[row][col] = 0;
        }
    }
    
    return false;
}

int main()
{
    /*sample input-

    0 0 0 2 6 0 7 0 1
    6 8 0 0 7 0 0 9 0
    1 9 0 0 0 4 5 0 0
    8 2 0 1 0 0 0 4 0
    0 0 4 6 0 2 9 0 0
    0 5 0 0 0 3 0 2 8
    0 0 9 3 0 0 0 7 4
    0 4 0 0 5 0 0 3 6
    7 0 3 0 1 8 0 0 0

    3 0 6 5 0 8 4 0 0 
    5 2 0 0 0 0 0 0 0 
    0 8 7 0 0 0 0 3 1 
    0 0 3 0 1 0 0 8 0 
    9 0 0 8 6 3 0 0 5 
    0 5 0 0 9 0 6 0 0 
    1 3 0 0 0 0 2 5 0 
    0 0 0 0 0 0 0 7 4 
    0 0 5 2 0 6 3 0 0 
    
    */

    int grid[9][9];
    for(int i = 0; i<9; i++){
        for(int j =0; j<9; j++){
            cin>>grid[i][j];
            }
    }

    if (SolveSudoku(grid) == true){

        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
                cout << grid[row][col] << " ";
            cout << endl;
        }
    }
    else
        cout << "No solution exists for the given sudoku";
 
    return 0;
}