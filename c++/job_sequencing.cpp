#include<bits/stdc++.h>
using namespace std;
 
typedef struct Job
{
   string name; 
   int dead;    
   int profit; 
}job;

void bubble(job a[],int n)
{
    job t;
    int i,j;
    for ( i = 0; i < n-1; i++)
    {
        for ( j = 0; j < n-i-1; j++)
        {
            if(a[j].profit<a[j+1].profit)
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }

}

void seq(job a[],int n)
{
    string nm[n];
    int s[n]={0};
    int i,j,c;c=0;

    // ASSUMED 1 UNIT OF TIME IS TAKEN TO COMPLETE THE TASK
    for ( i = 0; i < n; i++)
    {
        for ( j = (a[i].dead-1); j >= 0; j--)
        {
            if(s[j]==0)
            {
                c++;                // COUNTS NUMBER OF JOBS GIVING MAXIMUM PROFIT
                s[j]=1;   
                nm[j]=a[i].name;   //STORES NAMES
                break;
            }
        }
        
    }

    cout<<"MAXIMUM PROFIT GIVING JOBS  NAME\n";

    for ( i = 0; i < n; i++)
    if(s[i]==1)
    cout<<nm[i]<<" ";
    
}

int main()
{
    int i,n;
    cin>>n;
    job a[n];

    for ( i = 0; i < n; i++)
    {
        cout<<"ENETER NAME DEADLINE AND PROFIT OF "<<i+1<<"\n";
        cin>>a[i].name>>a[i].dead>>a[i].profit;
    }

    // SORTING IN DECREASING ORDER OF PROFIT
    bubble(a,n);

    // for ( i = 0; i < n; i++)
    // cout<<a[i].name<<"\t"<<a[i].dead<<"\t"<<a[i].profit<<"\n";

    cout<<"\n";
    seq(a,n);
  
}

        
      
 