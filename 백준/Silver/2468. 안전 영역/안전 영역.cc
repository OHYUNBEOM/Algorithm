#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int n,mx,ny,nx,cntt;
int a[104][104];
int visited[104][104];
vector<int> v;
void DFS(int y,int x)
{
	visited[y][x]=1;
	for(int i=0;i<4;i++)
	{
		ny = y + dy[i];
		nx = x + dx[i];
		if(ny<0 || ny>=n || nx<0 || nx>=n || a[ny][nx]<=mx || visited[ny][nx]==1) continue;
		if(a[ny][nx]>mx)
		{
			DFS(ny,nx);
		}
	}
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
			mx = max(mx,a[i][j]);
		}
	}
	while(mx--)
	{
		memset(visited,0,sizeof(visited));
		int ret=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(a[i][j]>mx && visited[i][j]==0)
				{
					ret++;
					DFS(i,j);
				}
			}
		}
		v.push_back(ret);
	}
	for(int vv : v)
	{
		cntt = max(cntt,vv);
	}
	cout<<cntt<<"\n";
}