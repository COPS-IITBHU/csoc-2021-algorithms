# -*- coding: utf-8 -*-
"""
Created on Fri Sep 10 13:52:02 2021
"""

value=[int(x) for x in input().split()]
weight=[int(x) for x in input().split()]
w=int(input())
n=int(len(value))
dp=[]
for i in range(n+1):
    l=[]
    for j in range(w+1):
        l.append(0)
    dp.append(l)
for i in range(n+1):
    for j in range(w+1):
        if (i==0 or j==0):
            dp[i][j]=0
        elif (weight[i-1]>w):
            dp[i][j]=dp[i-1][j]
        else:
            ind=j-weight[i-1]
            dp[i][j]=max(value[i-1]+dp[i-1][ind],dp[i-1][j])
ans=dp[n][w]
print(ans)