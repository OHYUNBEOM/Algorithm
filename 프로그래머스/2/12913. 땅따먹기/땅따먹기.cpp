#include<bits/stdc++.h>
using namespace std;
int dp[100004][4];
int solution(vector<vector<int>> land)
{
    int n = land.size();
    for(int i=0;i<4;i++)
    {
        dp[0][i]=land[0][i];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<4;j++)
        {
            int prev=0;
            for(int k=0;k<4;k++)
            {
                if(j==k) continue;
                prev=max(prev,dp[i-1][k]);
            }
            dp[i][j]=land[i][j]+prev;
        }
    }
    return *max_element(dp[n-1],dp[n-1]+4);
}