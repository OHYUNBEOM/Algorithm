#include<bits/stdc++.h>
using namespace std;
const int dy[]={-1,0,1,0};
const int dx[]={0,1,0,-1};
int n,m;
int s_x,s_y,l_x,l_y,e_x,e_y;
char c[104][104];
int visited[104][104];
int bfs(int start_y,int start_x,int end_y,int end_x)
{
    memset(visited,0,sizeof(visited));
    visited[start_y][start_x]=1;
    queue<pair<int,int>> q;
    q.push({start_y,start_x});
    while(q.size())
    {
        int y,x;
        tie(y,x)=q.front(); q.pop();
        if(y==end_y && x==end_x)
        {
            return visited[y][x]-1;
        }
        for(int i=0;i<4;i++)
        {
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(ny<0 || ny>=n || nx<0 || nx>=m || visited[ny][nx] || c[ny][nx]=='X') continue;
            visited[ny][nx]=visited[y][x]+1;
            q.push({ny,nx});
        }
    }
    return 0;
}
int solution(vector<string> maps) {
    n=maps.size();
    m=maps[0].size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            c[i][j]=maps[i][j];
            if(maps[i][j]=='S')
            {
                s_y=i;
                s_x=j;
            }
            else if(maps[i][j]=='E')
            {
                e_y=i;
                e_x=j;
            }
            else if(maps[i][j]=='L')
            {
                l_y=i;
                l_x=j;
            }
        }
    }
    int dist1=bfs(s_y,s_x,l_y,l_x); //S -> L
    int dist2=bfs(l_y,l_x,e_y,e_x); //L -> E
    if(dist1==0 || dist2==0) return -1;
    else return dist1+dist2;
}