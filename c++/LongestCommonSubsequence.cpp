#include <iostream>
#include <string.h>
using namespace std;
int maximum(int p,int q){
    if(p>q)
        return p;
    else
        return q;
}
int longestSequence(string string1, string string2,int len1,int len2){
    if(len1==0 || len2==0)
        return 0;
    else if(string1[len1-1]==string2[len2-1])
        return 1+longestSequence(string1,string2,len1-1,len2-1);
    else if(string1[len1-1]!=string2[len2-1])
        return maximum(longestSequence(string1,string2,len1,len2-1),longestSequence(string1,string2,len1-1,len2));
}
int main(){
    string string1,string2;
    cout<<"Enter first string : ";
    getline(cin,string1);
    int len1=string1.size();
    cout<<"Enter second string : ";
    getline(cin,string2);
    int len2=string2.size();
    if(len1==0 || len2==0)
         cout<<"The longest common subsequence is of 0 character";
    else{
       int seq_len=longestSequence(string1,string2,len1,len2);
       cout<<"The longest common subsequence is of "<<seq_len<<" characters";
    }
    return 0;
}
