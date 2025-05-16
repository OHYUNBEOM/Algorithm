#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int tc,n,m,k,y,x,cnt,ny,nx;
int a[54][54];
int visited[54][54];
void DFS(int sy,int sx)
{
	visited[sy][sx]=1;
	for(int i=0;i<4;i++)
	{
		ny = sy+dy[i];
		nx = sx+dx[i];
		if(ny<0 || ny>=n || nx<0 || nx>=m || visited[ny][nx]) continue;
		if(a[ny][nx]==1 && !visited[ny][nx])
		{
			DFS(ny,nx);
		}
	}
}
int main()
{
	cin>>tc;
	for(int i=0;i<tc;i++)
	{
		memset(a,0,sizeof(a));
		memset(visited,0,sizeof(visited));
		cnt=0;
		cin>>n>>m>>k;
		for(int i=0;i<k;i++)
		{
			cin>>y>>x;
			a[y][x]=1;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(a[i][j]==1 && visited[i][j]==0)
				{
					cnt++;
					DFS(i,j);
				}
			}
		}
		cout<<cnt<<"\n";
	}
}
