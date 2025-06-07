#include<bits/stdc++.h>
using namespace std;
const int dy[]={-1,0,1,0};
const int dx[]={0,1,0,-1};
int n,m,ret=INT_MIN;
char a[54][54];
int visited[54][54];
void BFS(int sy,int sx)
{
	visited[sy][sx]=1;
	queue<pair<int,int>> q;
	q.push({sy,sx});
	while(q.size())
	{
		int y,x;
		tie(y,x)=q.front();q.pop();
		for(int i=0;i<4;i++)
		{
			int ny=y+dy[i];
			int nx=x+dx[i];
			if(ny<0 || ny>=n || nx<0 || nx>=m || visited[ny][nx] || a[ny][nx]=='W') continue;
			if(a[ny][nx]=='L')
			{
				visited[ny][nx]=visited[y][x]+1;
				ret=max(ret,visited[ny][nx]-1);
				q.push({ny,nx});
			}
		}
	}
	return;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j]=='L')
			{
				memset(visited,0,sizeof(visited));
				BFS(i,j);
			}
		}
	}
	cout<<ret;
}