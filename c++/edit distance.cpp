#include<iostream>
#include<string>
 
using namespace std;
 
int min(string s, string d, int l1, int l2)
{
    int i, j;
    int e[l1+1][l2+1];
    for(i=0;i<=l1;i++)
        e[i][0]=i;    
    for(j=0;j<=l2;j++)
        e[0][j]=j;   
    for(i=1;i<=l1;i++)
    {
        for(j=1;j<=l2;j++)
        {
            if(s[i-1]==d[j-1])
            {
                e[i][j]=e[i-1][j-1];
            }
 
            else
            {
                int x=1+e[i-1][j];     
                int y=1+e[i][j-1];    
                int z=1+e[i-1][j-1];  
 
                e[i][j]=min(x,min(y,z));
 
            }
        }
    }
 
    return e[l1][l2];
 
}
 
 
int main()
{
    string s,d;
 
    getline(cin, s);
 
    getline(cin, d);
 
    int l1=s.length();  
    int l2=d.length(); 
 
    cout<<min(s,d,l1,l2);
 
    cout<<endl;
    return 0;
}