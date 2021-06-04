//Longest Pallindromic Subsequence
#include<bits/stdc++.h>
using namespace std;
int lps(string s, int i, int j){
	if(i==j)
		return 1;
	if(s[i]==s[j] && j-i==1)
		return 2;
	if(s[i]==s[j])
		return lps(s, i+1, j-1)+2;
	return max(lps(s, i+1, j), lps(s, i, j-1));
}

int main(){
	string s;	cin>>s;
	int n=s.length();
	cout<<"Length of longest pallindromic subsequence = "<<lps(s, 0, n-1)<<endl;
}
