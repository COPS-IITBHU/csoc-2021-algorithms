#include <bits/stdc++.h>
using namespace std;

void NaivePatternSearching(string s1, string s2)
{
    int x = s1.size();
    int y = s2.size();

    for (int i = 0; i <= y - x; i++) {
        int j;
        for (j = 0; j < x; j++){
            if (s2[i + j] != s1[j])
                break;
        }
            
        if (j == x) {
            cout << "Found at index: "<< i << endl;
        }
            
    }
}