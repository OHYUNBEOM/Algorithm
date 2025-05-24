#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int n,l,r,ny,nx;
bool flag;
int a[54][54];
int a_copy[54][54];
int visited[54][54];
void bfs(int sy,int sx)
{
	visited[sy][sx]=1;
	queue<pair<int,int>> q;
	vector<pair<int,int>> united;
	q.push({sy,sx});
	united.push_back({sy,sx});
	int sum=a[sy][sx];
	int cnt=1;
	while(q.size())
	{
		int y,x;
		tie(y,x) = q.front(); q.pop();
		for(int i=0;i<4;i++)
		{
			ny=y+dy[i];
			nx=x+dx[i];
			if(ny<0 || ny>=n || nx<0 || nx>=n || visited[ny][nx]) continue;
			int diff = abs(a[y][x]-a[ny][nx]);
			if(diff>=l && diff<=r)
			{
				visited[ny][nx]=1;
				q.push({ny,nx});
				united.push_back({ny,nx});
				sum+=a[ny][nx];
				cnt++;
			}
		}
	}
	if(cnt>1)
	{
		int avg = sum/cnt;
		for(auto it : united)
		{
			a[it.first][it.second]=avg;
		}
		flag=true;
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
		flag=false;
		memset(visited,0,sizeof(visited));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(!visited[i][j])
				{
					bfs(i,j);
				}
			}
		}
		if(!flag) break;
		day++;
	}
	cout<<day;
}