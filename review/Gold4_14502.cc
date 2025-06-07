#include<bits/stdc++.h>
using namespace std;
const int dy[]={-1,0,1,0};
const int dx[]={0,1,0,-1};
int n,m,ret;
int a[10][10];
int a_copy[10][10];
int visited[10][10];
vector<pair<int,int>> safe;
void DFS(int y,int x)
{
	visited[y][x]=1;
	for(int i=0;i<4;i++)
	{
		int ny = y+dy[i];
		int nx = x+dx[i];
		if(ny<0 || ny>=n || nx<0 || nx>=m || visited[ny][nx] || a_copy[ny][nx]==1) continue;
		if(a_copy[ny][nx]==0)
		{
			visited[ny][nx]=1;
			a_copy[ny][nx]=2;
			DFS(ny,nx);
		}
	}
}
void combi(int start, vector<pair<int,int>> &b)
{
	if(b.size()==3)
	{
		int cnt=0;	
		memcpy(a_copy,a,sizeof(a));
		for(auto it : b)
		{
			a_copy[it.first][it.second]=1;
		}
		memset(visited,0,sizeof(visited));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(a_copy[i][j]==2)
				{
					DFS(i,j);
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(a_copy[i][j]==0)
				{
					cnt++;
				}
			}
		}
		ret=max(ret,cnt);
		return;
	}
	for(int i=start+1;i<safe.size();i++)
	{
		b.push_back(safe[i]);
		combi(i,b);
		b.pop_back();
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
			if(a[i][j]==0) safe.push_back({i,j});
		}
	}
	vector<pair<int,int>> v;
	combi(-1,v);
	cout<<ret;
}
