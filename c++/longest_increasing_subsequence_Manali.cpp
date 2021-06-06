# include<iostream>
using namespace std;
int increasinglist(int arr[],int m)
{
    int t,s,maximum=0,*increasinglist;
    increasinglist = (int*)malloc(sizeof(int) *m);
    for (t=0;t<m; t++){
        increasinglist[t]=1;
    }
    for (t=1; t<m;t++)
    {
        for(s=0;s<t;s++){
            if (arr[t]>arr[s] && increasinglist[t]< increasinglist[s]+1){
                increasinglist[t]=increasinglist[s]+1;
            }
        }
    }
    for(t=0;t<m;t++){
        if(maximum < increasinglist[t]){
            maximum=increasinglist[t];
        }
    }
    free(increasinglist);
    return maximum;

}

int main(){
    int arr[] ={35,65,23,12,76,89,3,27};
    int m= sizeof(arr)/sizeof(arr[0]);
    cout<<" The length of the increasing subsequence is : "<<increasinglist(arr,m);

}