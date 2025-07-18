#include<bits/stdc++.h>
using namespace std;
int dp[504][504];
int solution(vector<vector<int>> triangle) {
    dp[0][0]=triangle[0][0];
    int n=triangle.size();
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j==0) dp[i][j]=triangle[i][j]+dp[i-1][j];
            else if(j==i) dp[i][j]=triangle[i][j]+dp[i-1][j-1];
            else dp[i][j]=triangle[i][j]+max(dp[i-1][j-1],dp[i-1][j]);
        }
    }
    return *max_element(dp[n-1],dp[n-1]+n);
}