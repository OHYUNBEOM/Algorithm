#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int n,l,r,ny,nx,sum;
int a[54][54];
int visited[54][54];
vector<pair<int,int>> united;
void dfs(int y,int x)
{
	visited[y][x]=1;
	united.push_back({y,x});
	sum+=a[y][x];
	for(int i=0;i<4;i++)
	{
		ny=y+dy[i];
		nx=x+dx[i];
		if(ny<0 || ny>=n || nx<0 || nx>=n || visited[ny][nx]) continue;
		int diff=abs(a[y][x]-a[ny][nx]);
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
	int day=0;
	while(true)
	{
		bool flag=false;
		memset(visited,0,sizeof(visited));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(!visited[i][j])
				{
					sum=0;
					united.clear();
					dfs(i,j);
					if(united.size()>1)
					{
						flag=true;
						int avg=sum/united.size();
						for(auto it : united)
						{
							a[it.first][it.second]=avg;
						}
					}
				}
			}
		}
		if(!flag) break;
		day++;
	}
	cout<<day;
}