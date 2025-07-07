#include<bits/stdc++.h>
using namespace std;
int a[204][204];
int visited[204];
int nn,cnt;
void DFS(int node)
{
    visited[node]=1;
    for(int i=0;i<nn;i++)
    {
        if(!visited[i] && a[node][i]==1)
        {
            DFS(i);
        }
    }
    return;
}
int solution(int n, vector<vector<int>> computers) {
    nn=n;
    for(int i=0;i<nn;i++)
    {
        for(int j=0;j<nn;j++)
        {
            a[i][j]=computers[i][j];
        }
    }
    
    for(int i=0;i<nn;i++)
    {
        if(!visited[i])
        {
            DFS(i);
            cnt++;
        }
    }
    return cnt;
}