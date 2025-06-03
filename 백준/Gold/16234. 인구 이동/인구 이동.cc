#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int n,l,r,ny,nx,ret;
int a[54][54];
bool visited[54][54];
vector<pair<int,int>> united;
void dfs(int y,int x)
{
	visited[y][x]=1;
	united.push_back({y,x});
	for(int i=0;i<4;i++)
	{
		ny=y+dy[i];
		nx=x+dx[i];
		if(ny<0 || ny>=n || nx<0 || nx>=n || visited[ny][nx]) continue;
		int diff = abs(a[ny][nx]-a[y][x]);
		if(diff>=l && diff<=r)
		{
			dfs(ny,nx);
		}
	}
}
int main()
{
	cin>>n>>l>>r;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];	
		}
	}
	while(true)
	{
		bool flag=true; // 인구 이동 판단 
		memset(visited,false,sizeof(visited));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(!visited[i][j])
				{
					int sum=0;
					united.clear();
					dfs(i,j); // 연합이 가능한곳 : united에 좌표로 저장됨 
					if(united.size()>1)
					{
						flag=false;
						for(auto it : united)
						{
							sum+=a[it.first][it.second];
						}
						int avg = sum/united.size();
						for(auto it : united)
						{
							a[it.first][it.second]=avg;
						}
					}
				}
			}
		}
		if(flag) break;
		else ret++; // 인구 이동 일수 
	}
	cout<<ret;
}