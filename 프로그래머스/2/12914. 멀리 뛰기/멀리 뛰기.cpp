#include<bits/stdc++.h>
const int MOD=1234567;
using namespace std;
long long solution(int n) {
    long long dp[2004]={0,};
    dp[0]=1;
    for(int i=0;i<=n;i++)
    {
        dp[i+1]=(dp[i+1]+dp[i])%MOD;
        dp[i+2]=(dp[i+2]+dp[i])%MOD;
    }
    return dp[n];
}