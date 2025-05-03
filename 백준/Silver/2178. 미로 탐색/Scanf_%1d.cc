#include<bits/stdc++.h>
using namespace std;
int n,m,nx,ny,xx,yy;
int a[104][104];
int visited[104][104];
const int dy[4]={-1,0,1,0};
const int dx[4]={0,1,0,-1};
void BFS(int y,int x)
{
	queue<pair<int,int>> q;
	visited[y][x]=1;
	q.push({y,x});
	while(q.size())
	{
		tie(yy,xx) = q.front(); q.pop();
		for(int i=0;i<4;i++)
		{
			ny = yy + dy[i];
			nx = xx + dx[i];
			if(ny <0 || ny >= n || nx <0 || nx >=m || a[ny][nx]==0) continue;
			if(visited[ny][nx]) continue;
			visited[ny][nx] = visited[yy][xx]+1;	
			q.push({ny,nx});
		}
	}
}
int main()
{
	scanf("%d %d", &n,&m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%1d",&a[i][j]);
		}
	}
	BFS(0,0);
	printf("%d",visited[n-1][m-1]); // include start / if not, -1 
}
