//0-1 knapsack problem
//Solving by tabulation

#include <vector>
#include<iostream>
#define max(a, b) (a>b)?a:b

using namespace std;

int main(){
    vector<pair<int, int>> item{make_pair(2, 15), make_pair(3, 40), make_pair(1, 10)};    //(weight, value)
    int max_weight=6;
    int num_items = item.size();

    int table[num_items+1][max_weight+1]={0};
    for(int i=0; i< num_items+1; i++){
        for(int j=0; j<max_weight+1; j++){
           table[i][j]=0;
        }

    }

    for(int i=1; i<num_items+1; i++){
        for(int j=1; j<max_weight+1; j++){
            if(j<item[i-1].first)
                table[i][j]=table[i-1][j];
            else
                table[i][j]= max(item[i-1].second+table[i-1][j-item[i-1].first], table[i-1][j]);
        }
    }


    int answer= table[num_items][max_weight];
    cout<<answer;

}