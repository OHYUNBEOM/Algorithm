#include<bits/stdc++.h>
using namespace std;
int n,m,ret;
int a[104][104];
bool visited[104][104];
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
void DFS(int y,int x)
{
	visited[y][x]=1;
	for(int i=0;i<4;i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny<0 || ny>=n || nx<0 || nx>=m) continue;
		if(a[ny][nx] && !(visited[ny][nx])) DFS(ny,nx);
	}
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
			if(a[i][j]==1 && !(visited[i][j]))
			{
				ret++;
				DFS(i,j);
			}
		}
	}
	cout<<ret;
	return 0;
}
