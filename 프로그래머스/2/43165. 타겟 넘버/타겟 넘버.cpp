#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int tgt,ans;
void dfs(int idx,int sum)
{
    if(idx==v.size())
    {
        if(sum==tgt) ans++;
        return;
    }
    dfs(idx+1,sum+v[idx]);
    dfs(idx+1,sum-v[idx]);
}
int solution(vector<int> numbers, int target) {
    v=numbers;
    tgt=target;
    ans=0;
    dfs(0,0);
    return ans;
}