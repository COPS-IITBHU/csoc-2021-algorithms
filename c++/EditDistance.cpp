#include<bits/stdc++.h>
using namespace std;

int ED(string x, string y) 
{
  int a= x.size();
  int b = y.size();

  int **ed = new int * [x.size() + 1];

  for (int i = 0; i < x.size() + 1; i++) 
    ed[i] = new int[y.size() + 1];

  ed[0][0] = 0;

  for (int i = 1; i < a + 1; i++)
    ed[i][0] = i;
    
  for (int i = 1; i < b + 1; i++)
    ed[0][i] = i;

  for (int i = 1; i < a + 1; i++) 
  {
    for (int j = 1; j < b + 1; j++) 
    {
      if (x[a - i] == y[b - j])
        ed[i][j] = ed[i - 1][j - 1];

      else
        ed[i][j] = 1 + min(ed[i][j - 1], min(ed[i - 1][j], ed[i - 1][j - 1]));

    }
  }

  return ed[a][b];

}


int main() 
{
  string x,y;
  cin >> x >> y;
  cout << ED(x, y) << endl;
  return 0;
}

