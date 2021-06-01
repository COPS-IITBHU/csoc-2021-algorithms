#include <bits/stdc++.h>
using namespace std;

vector <int> search_stringSearch(string search_string,string string);

int main()
{
	string s;
    string search_s;
	vector <int> index;
	cout<<"Enter the string here : ";
	getline(cin,s);
	cout<<"Enter the pattern you want to search here : ";
	getline(cin,search_s);
	search_stringSearch(search_s, s);
	index=search_stringSearch(search_s, s);
	cout << "The entered search_string occurs in the entered stringing at:   "<<endl;
	for(int i=0;i<index.size();i++)
	cout<<index[i]<<" ";
	return 0;
}

vector <int> search_stringSearch(string search_string,string string)
{
	int m = search_string.size();
	int n = string.size();
	vector <int> a;

	for (int i = 0; i <= n - m; i++) {
		int j;

		for (j = 0; j < m; j++)
			if (string[i + j] != search_string[j])
				break;
        if (j == m)
			a.push_back(i);
	}
	return a;
}



