#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

template <typename T>
void dfs(vector<vector<T>> adjacency_matrix,vector<bool> & visited,T v,vector<T> &ans){
    visited[v] = true;
    for (int u: adjacency_matrix[v]) {
        if (!visited[u]) {
            dfs(adjacency_matrix,visited,u,ans);
        }
    }
    ans.push_back(v);
    
}
template <typename T>                       // for int,long,long long etc
vector<T> topological_sort(vector<vector<T>> & adjacency_matrix) {
    vector<bool> visited(adjacency_matrix.size(),false);
    vector<T> ans;
    for (int i=0;i<adjacency_matrix.size();i++) {
        if (!visited[i]) {
            dfs<T>(adjacency_matrix,visited,i,ans);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main() {
    int vertices,edges;
    cin >> vertices>>edges;
    vector<vector<int>> adjacency_matrix(vertices);
    for (int i=0;i<edges;i++) {
        int left,right;
        cin >> left>>right;             // directed edge is assumed to be left->right
        left--;right--;
        adjacency_matrix[left].push_back(right);  
    }
    vector<int> ans = topological_sort<int>(adjacency_matrix);
    for (auto ele:ans) {
        cout <<ele+1 <<' ';
    }
}

/*
Testcases
Test case 1 :
    5 6
    1 2
    1 3 
    2 4
    2 3
    3 4
    3 5

Expected output:
    1 2 3 5 4

Test case 2:
    6 6
    6 1
    6 3
    3 4
    4 2
    5 2
    5 1
Expected output :
    6 5 3 4 2 1

*/