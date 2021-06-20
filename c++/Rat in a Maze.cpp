#include <bits/stdc++.h>

using namespace std;

const int N = 4;

bool solvemazer(int maze[N][N], int x, int y, int sol[N][N]);

void psol(int sol[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", sol[i][j]);
        printf("\n");
    }
}
bool move(int maze[N][N], int x, int y)
{
    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
        return true;

    return false;
}
bool solveMaze(int maze[N][N])
{
    int sol[N][N] = {{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0}};
    if (solvemazer(maze, 0, 0, sol) == false)
    {
        cout << "Solution doesn't exist";
        return false;
    }

    psol(sol);
    return true;
}
bool solvemazer(int maze[N][N], int x, int y, int sol[N][N])
{
    if (
        x == N - 1 && y == N - 1 && maze[x][y] == 1)
    {
        sol[x][y] = 1;
        return true;
    }
    if (move(maze, x, y) == true)
    {
        if (sol[x][y] == 1)
            return false;
        sol[x][y] = 1;
        if (solvemazer(maze, x + 1, y, sol) == true)
            return true;
        if (solvemazer(maze, x, y + 1, sol) == true)
            return true;
        if (solvemazer(maze, x - 1, y, sol) == true)
            return true;
        if (solvemazer(maze, x, y - 1, sol) == true)
            return true;
        sol[x][y] = 0;
        return false;
    }
    return false;
}

int main()
{

    int maze[N][N] ; 
    cout<<"Enter a "<<N<<"X"<<N<<" matrix denoting path\n";
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>maze[i][j];
        }
    }
    solveMaze(maze);
    return 0;
}
