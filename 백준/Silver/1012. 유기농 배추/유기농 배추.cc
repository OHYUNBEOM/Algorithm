#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int tc,m,n,k,ret,ny,nx;
int a[54][54];
int visited[54][54];
void DFS(int sy,int sx)
{
	visited[sy][sx]=1;
	for(int i=0;i<4;i++)
	{
		ny = sy + dy[i];
		nx = sx + dx[i];
		if(ny<0 || ny>=n || nx<0 || nx>=m) continue;
		if(a[ny][nx]==1 && visited[ny][nx]==0)
		{
			DFS(ny,nx);
		}
	}
	return;
}
int main()
{
	cin>>tc;
	for(int i=0;i<tc;i++)
	{
		memset(a,0,sizeof(a));
		memset(visited,0,sizeof(visited));
		cin>>m>>n>>k;
		for(int i=0;i<k;i++)
		{
			int y,x;
			cin>>x>>y;
			a[y][x]=1;
		}
		ret=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(a[i][j]==1 && !(visited[i][j]))
				{
					ret++;
					DFS(i,j);
				}
			}
		}
		cout<<ret<<"\n";
	}
}