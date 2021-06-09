#include <iostream>
using namespace std;
bool issafe(int i, int j, int n, int **ar)           //function to check if rat can move to a block 
{
    if ((ar[i][j] == 1) && (i < n) && (j < n))
        return true;
    else
        return false;
}
bool ratinmaze(int i, int j, int n, int **ar, int **sol)   //main driver function
{
    if ((i == (n - 1)) && (j == (n - 1))){
        sol[i][j] = 1;
        return true;
    }

    if (issafe(i, j, n, ar))
    {
        sol[i][j] = 1;
        if (ratinmaze(i + 1, j, n, ar, sol))              // to check if the rat can go down
        {
            return true;
        }
        if (ratinmaze(i, j + 1, n, ar, sol))              // to check if the rat can go right
        {
            return true;
        }
        sol[i][j] = 0;
        return false;
    }
    return false;
}

int main()
{

    int n;
    cin >> n;

    int** ar=new int*[n];
    
    for (int i = 0; i < n; ++i)
    {   ar[i]=new int [n];
        for (int j = 0; j < n; ++j)
        {
            cin >> ar[i][j];      // 0 denotes a blocked path and 1 represents an open path where the rat can move 
        }
    }
    
    int **sol =new int *[n];
    for (int i = 0; i < n; ++i)
    {   sol[i]=new int [n];
        for (int j = 0; j < n; ++j)
            sol[i][j] = 0;
    }
    cout<<endl;
    if (ratinmaze(0, 0, n, ar, sol))
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
                cout << sol[i][j] << " ";       // array gives the path on which the rat will move,
                cout << endl;                   // 1 represents the path on which the rat will move
        }
    }
    return 0;
}