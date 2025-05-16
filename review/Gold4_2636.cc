#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int n,m,cnt1,cnt2,ny,nx;
int a[104][104];
int visited[104][104];
vector<pair<int,int>> v;
void DFS(int y,int x)
{
	visited[y][x]=1;
	if(a[y][x]==1)
	{
		v.push_back({y,x});
		return;
	}
	for(int i=0;i<4;i++)
	{
		ny = y + dy[i];
		nx = x + dx[i];
		if(ny<0 || ny>=n || nx<0 || nx>=m || visited[ny][nx]) continue;
		DFS(ny,nx);
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
	while(true)
	{
		memset(visited,0,sizeof(visited));
		v.clear();
		DFS(0,0);
		cnt1++;
		cnt2=v.size();
		for(int i=0;i<v.size();i++)
		{
			a[v[i].first][v[i].second]=0;
		}
		bool flag=1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(a[i][j]!=0)
				{
					flag=0;
				}
			}
		}
		if(flag==1) break;
	}
	cout<<cnt1<<"\n"<<cnt2;
}
