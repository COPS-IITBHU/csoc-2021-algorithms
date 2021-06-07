#include <bits/stdc++.h>
using namespace std;

void guptavishu1000()
{

    int n,W;
    // n is number of item available
    // W is the capacity of knapsack or maximum weight knapsack can hold
    // Enter number of items available : 
    cin>>n;
    // Enter capacity of knapsack or maximum weight knapsack can hold : 
    cin>>W;

    vector<int> v(n+1),w(n+1),dp(W+10);
    // v stores the values of each item 
    // w stores the weight associated with each item 
    // W stores the maximum value for each weights

    // Enter Values of item available and Weight associated with each value in each new line (with space between them)
    for(int i=1;i<=n;i++){
        cin >> v[i] >> w[i];
    }

    for(int i=1;i<=n;i++)
    {
        for(int wt=W;wt>=0;wt--)
        {
            if(wt>=w[i])
                dp[wt]=max(dp[wt], v[i]+dp[wt-w[i]]);
        }
    }
    
    cout<<"Maximum Value associated with Weight "<<W<<" is :"<<dp[W]<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(NULL); 
    cout.tie(NULL);

    guptavishu1000();
    return 0;
}


