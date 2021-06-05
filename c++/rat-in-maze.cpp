// Given a 2D matrix with obstacles (entries with zero considered obstacle and entries with one considered as open block )
// Start from (0,0) (or top-most and left-most block) to right-most and down-most block.
// If you are at (x,y) you can move (x+1,y) or (x,y+1)
// you cannot move to the walls


// this algorithm return path need to follow if there is any path exist (keeping in mind ,if you are at (x,y) you can move (x+1,y) or (x,y+1))
// If no path it will return nothing


#include <bits/stdc++.h>
using namespace std;

bool safeMove(int** arr, int x,int y , int n,int m){     // define a bool function to check whether we can go in next box or not
   if (x<m && y<n && arr[x][y]==1){return true;}
    return false;
}

bool ratInMaze(int** arr, int x,int y,int n,int m ,int**solution){  // backtracking and path deciding function , it uses recursion 


   if(x == m-1 && y == n-1){
       solution[x][y] = 1;
       return true;
   } 


   if (safeMove(arr,x,y,n,m)){
     solution[x][y] = 1;
     if (ratInMaze(arr ,x+1,y,n,m,solution)){
         return true;
     }
     if(ratInMaze(arr ,x,y+1,n,m,solution)){
         return true;
     }
     solution[x][y]=0;
     return false; 
   }
    return false;



}

int main(){

int n,m;    // inputs where  n is length of matrix and m is height of matrix 
cin>>n>>m;
int** arr = new int*[m];
for(int i=0;i<m;i++){              // taking our maze input
    arr[i] = new int[n];
}
for (int i=0;i<m;i++){
    for (int j=0;j<n;j++){
        cin>>arr[i][j];
    }
}

int** solution = new int*[m];    // initially assigning zero to solution array
for(int i=0;i<m;i++){
    solution[i] = new int[n];
for(int j=0;j<n;j++){
    solution[i][j]=0;
}
}

if(ratInMaze(arr,0,0,n,m,solution)){
    cout<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<solution[i][j]<<' ';  // print final maze path
        }cout<<endl;
    }
}else{cout<<"no path finded";}


return 0;

}
