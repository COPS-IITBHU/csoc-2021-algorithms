#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    char s[] = "This is naive algo for pattern searching";
    char p[] = "algo";
    int x = strlen(p);
    int y = strlen(s);
 
    for (int i = 0; i <= y - x; i++) {
        int j;
        for (j = 0; j < x; j++){
            if (s[i + j] != p[j]){
                break;
            }
        }
        if (j == x){
            cout << "starting index "<<i<<"\n";
        }
    }
    return 0;
}

//starting index 14
//space complexity O(1)
//time complexity O(x*(y-x+1))
 
