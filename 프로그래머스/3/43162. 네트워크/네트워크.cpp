#include<bits/stdc++.h>
using namespace std;
const int dy[]={-1,0,1,0};
const int dx[]={0,1,0,-1};
int a[204][204];
int visited[204];
int nn,ret;
void DFS(int node)
{
    visited[node]=1;
    for(int i=0;i<nn;i++)
    {
        if(a[node][i]==1 && !visited[i])
        {
            DFS(i);
        }
    }
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
            ret++;
            DFS(i);
        }
    }
    return ret;
}