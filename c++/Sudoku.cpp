#include <bits/stdc++.h>
using namespace std;
 
bool Safe(int arr[9][9], int r,
                       int c, int n)
{
     
    // Check if we find the same num in a row
    for (int i = 0; i< 9; i++)
        if (arr[r][i] == n)
            return false;
 
    // Check if we find the same num in same column
    for (int i=0; i<9; i++)
        if (arr[i][c] == n)
            return false;
 
    // Check if we find the same num in sub 3x3 matrix
    int initial_r = r-r%3, initial_c = c-c%3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (arr[i + initial_r][j+initial_c] == n)
                return false;
     
    return true;
}
 
// Takes a partially filled-in grid and attempts to fill empty locations
bool suduko(int arr[9][9], int r, int c)
{
    // Check if we have reached the 8th row and 9th column  (0 indexed matrix)
    if (r == 8 && c == 9)
        return true;
 
    // Check if column value  becomes 9
    if (c==9) {
        r++;
        c= 0;}
   
    // Check if the current position of the grid already contains value != 0, we check for next column
    if (arr[r][c] != 0)
        return suduko(arr, r, c + 1);
 
    for (int n = 1; n <= 9; n++)
    {
         
        // Check if it is safe to place the num (1-9)  in the given row ,column
        if (Safe(arr, r, c, n))
        {
            arr[r][c] = n;
           
            //  Checking for next possibility for the next column
            if (suduko(arr, r, c + 1))
                return true;
        }
       
        // As the assumption was wrong, the cell goes back to zero
        arr[r][c] = 0;
    }
    return false;
}
 

int main()
{
    int arr[9][9];
    for(int i=0;i<9;i++){
      for(int j=0;j<9;j++){
        cin>>arr[i][j];
       }}
       
    if (suduko(arr, 0, 0))
        for(int i=0;i<9;i++){
          for(int j=0;j<9;j++)
            {cout << arr[i][j] << " ";}
        cout << endl;}
   
    else
        cout << "no solution  exists " << endl;
 
    return 0;
}
