#include<bits/stdc++.h>
using namespace std;
int main(){
    int i=0 ,j,  a[] = {1,3,5,7,9,11,13,14 } , sum=14;  //this method only works for sorted arrays to give pairs having a particular sum
    j = sizeof(a)/sizeof(int) - 1;      //it gives us n-1

    while(i<j){

        int curr_Sum = a[i] + a[j];

        if(curr_Sum > sum ){
            j--;        //since in sorted array if i moves it will only increase its value so j--
        }

        else if (curr_Sum < sum){
            i++;
        }

        else if(curr_Sum == sum){

            cout<<a[i]<<" ,"<<a[j]<<endl;
            i++;
            j--;
        }

    }

return 0;
}