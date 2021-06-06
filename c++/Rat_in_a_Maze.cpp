//Name: Ankur Agrawal
//Repo: https://github.com/Ankur-Agrawal-ece20

#include <bits/stdc++.h>
using namespace std;

// ******** Input & Output ****************
// Input no of rows and column then give matrix.
// If rat finds a way from (0,0) to (n-1,m-1) you will see output.
// Else a message of cannot reach is displayed!

// ******** Brief Explanation *************
// The two steps of taking input and giving output are obivious.
// The code works with 3 matrices that are given matrix, res(result) & visited.
// As we cannot pass 2d matrix so I worked with pointers.
// Also I took care of prev. node as well.
// Using prev. and visited rat can travel in all 4 directions to reach end.
// If there are many ans. then it may be possible that output may not give shortest path.

int n,m;
bool result(int* matrix,int *res, int x,int y, int* visited, int prev){
	if(x==n || y==m ||x<0 || y<0) return false;
	if((*((visited+m*x)+y))==1) return false;
	else (*((visited+m*x)+y))=1;

	if(prev!=1 && (*((matrix+m*x)+y+1))!=0){
		if(x==n-1 && y==m-2) return true;
		if(result(matrix,res, x,y+1,visited,3)){
			(*((res+m*x)+y+1))=1;
			return true;
		}
	}
	if(prev!=2 && (*((matrix+m*(x+1))+y))!=0){
		if(x==n-2 && y==m-1) return true;
		if(result(matrix,res, x+1,y,visited,4)){
			(*((res+m*(x+1))+y))=1;
			return true;
		}
	}
	if(prev!=3 && y>0 && (*((matrix+m*x)+y-1))!=0){
		if(result(matrix,res, x,y-1,visited,1)){
			(*((res+m*x)+y-1))=1;
			return true;
		}
	}
	if(prev!=4 && x>0 && (*((matrix+m*(x-1))+y))!=0){
		if(result(matrix,res, x-1,y,visited,2)){
			(*((res+m*(x-1))+y))=1;
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	int arr[n][m],res[n][m],visited[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			res[i][j]=0;
			visited[i][j]=0;
			cin>>arr[i][j];
		}
	}
	if(m==1 && n==1) cout<<"1";
	else if(!result((int*)arr,(int*)res,0,0,(int*)visited,0)){
		cout<<"Cannot reach";
	}
	else{
		res[0][0]=1;
		res[n-1][m-1]=1;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cout<<res[i][j]<<" ";
			}
		cout<<endl;
		}
	}
	return 0;
}
