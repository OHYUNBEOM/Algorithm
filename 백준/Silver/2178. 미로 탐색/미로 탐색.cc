#include<bits/stdc++.h>
using namespace std;
const int dy[]={-1,0,1,0};
const int dx[]={0,1,0,-1};
int n,m,y,x;
int a[104][104];
int visited[104][104];
void BFS(int sy,int sx)
{
	visited[sy][sx]=1;
	queue<pair<int,int>> q;
	q.push({sy,sx});
	while(q.size())
	{
		tie(y,x) = q.front();q.pop();
		for(int i=0;i<4;i++)
		{
			int ny=y+dy[i];
			int nx=x+dx[i];
			if(ny<0 || ny>=n || nx<0 || nx>=m || visited[ny][nx] || a[ny][nx]==0) continue;
			visited[ny][nx]=visited[y][x]+1;
			q.push({ny,nx});
		}
	}
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%1d",&a[i][j]);
		}
	}
	BFS(0,0);
	printf("%d",visited[n-1][m-1]);
}