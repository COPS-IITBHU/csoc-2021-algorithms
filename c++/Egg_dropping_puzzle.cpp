#include<iostream>
using namespace std;

int max(int a, int b) {
   return (a > b)? a: b;
}

int eggTrialCount(int eggs, int floors)  //minimum trials for worst case
{                            
   int minTrial[eggs+1][floors+1];    //to store minimum trials for ith egg and jth floor
   int res;

   for (int i = 1; i <= eggs; i++)  //one trial to check from first floor, and no trial for 0th floor 
  {                              
      minTrial[i][1] = 1;
      minTrial[i][0] = 0;
   }

   for (int j = 1; j <= floors; j++)    //when egg is 1, we need 1 trials for each floor
      minTrial[1][j] = j;

   for (int i = 2; i <= eggs; i++) {    //for 2 or more than 2 eggs
      for (int j = 2; j <= floors; j++) {    //for second or more than second floor
         minTrial[i][j] = INT8_MAX;
         for (int k = 1; k <= j; k++) {
            res = 1 + max(minTrial[i-1][k-1], minTrial[i][j-k]);
            if (res < minTrial[i][j])
               minTrial[i][j] = res;
         }
      }
   }

   return minTrial[eggs][floors];    //number of trials for asked egg and floor
}

int main () 
{
   int egg, maxFloor;
   cout << "Enter number of eggs: "; cin >> egg;
   cout << "Enter max Floor: "; cin >> maxFloor;
   cout << "Minimum number of trials: " << eggTrialCount(egg, maxFloor);
}
