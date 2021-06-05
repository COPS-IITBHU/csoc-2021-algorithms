#include<bits/stdc++.h>
using namespace std;
#define n 5 // We can change dimension of our square matrix by changing here only.

int PathMatrix[n][n]={0}; // Initializing the path matrix with all its elements as 0.

// Function to check whether the rat can go at a certain point in the maze or not.
bool PointIsPossible(int matrix[n][n], int row_index, int col_index){
	if(row_index>=0 && row_index<n && col_index>=0 && col_index<n && matrix[row_index][col_index]==1)
		return true;
	else 
		return false;
}

bool FoundaPath(int matrix[n][n], int row_index, int col_index){

	// Terminating condition, by checking if we have reached our destination or not.
	if(row_index==n-1 && col_index==n-1 && matrix[row_index][col_index]==1){
		PathMatrix[row_index][col_index]=1;
		return true;
	}

	else if(PointIsPossible(matrix, row_index, col_index) == true){
		PathMatrix[row_index][col_index] = 1;

		if(FoundaPath(matrix, row_index+1, col_index)==true) return true; // moving in +y direction
		else if(FoundaPath(matrix, row_index, col_index+1)==true) return true; // moving in +x direction
		else{
			PathMatrix[row_index][col_index] = 0;
			return false;
		}
	}
	else return false;
}

int main(){
	int matrix[n][n]={{1, 0, 0, 0, 0},
			{1, 1, 0, 1, 0},
			{0, 1, 1, 1, 0},
			{0, 0, 0, 1, 0},
			{1, 1, 1, 1, 1}
			};
	int intial_row_index=0;
	int intial_col_index=0;
	if(FoundaPath(matrix,intial_row_index,intial_col_index)==true){
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j) cout << PathMatrix[i][j] << " ";
			cout << "\n";
		}
	}
	else cout << "Rat can't escape the maze.\n:(\n";
	return 0;
}
