#include<bits/stdc++.h>
using namespace std;
int visited[10];
int n,ret=INT_MIN;
vector<vector<int>> global_dungeons;
void go(int k, int cnt)
{
    ret=max(ret,cnt);
    for(int i=0;i<n;i++)
    {
        if(!visited[i] && k>=global_dungeons[i][0])
        {
            visited[i]=true;
            go(k-global_dungeons[i][1],cnt+1);
            visited[i]=false;
        }
    }
}
int solution(int k, vector<vector<int>> dungeons) {
    n = dungeons.size();
    global_dungeons=dungeons;
    memset(visited,0,sizeof(visited));
    go(k,0);
    return ret;
}
