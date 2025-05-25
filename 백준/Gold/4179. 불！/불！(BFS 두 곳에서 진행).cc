#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int r,c;
char a[1004][1004];
int visited[1004][1004];
int visited_fire[1004][1004];
queue<pair<int,int>> q_fire;
queue<pair<int,int>> q_jinsoo;
bool flag=true;
void bfs_fire()
{
	while(q_fire.size())
	{
		int y,x;
		tie(y,x) = q_fire.front(); q_fire.pop();
		for(int i=0;i<4;i++)
		{
			int ny=y+dy[i];
			int nx=x+dx[i];
			if(ny<0 || ny>=r || nx<0 || nx>=c || visited_fire[ny][nx] || a[ny][nx]=='#') continue;
			visited_fire[ny][nx] = visited_fire[y][x]+1;
			q_fire.push({ny,nx});
		}
	}
}
void bfs_jinsoo()
{
	while(q_jinsoo.size())
	{
		int y,x;
		tie(y,x) = q_jinsoo.front(); q_jinsoo.pop();
		if(y==0 || x==0 || y==r-1 || x==c-1)
		{
			cout<<visited[y][x];
			flag=false;
			return;
		}
		for(int i=0;i<4;i++)
		{
			int ny=y+dy[i];
			int nx=x+dx[i];
			if(ny<0 || ny>=r || nx<0 || nx>=c || a[ny][nx]=='#' || visited[ny][nx]) continue;
			
			if(visited_fire[ny][nx]!=0 && visited_fire[ny][nx]<=visited[y][x]+1) continue;
			
			visited[ny][nx]=visited[y][x]+1;
			q_jinsoo.push({ny,nx});
		}
	}
}
int main()
{
	cin>>r>>c;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cin>>a[i][j]; 
		}
	}
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(a[i][j]=='F')
			{
				visited_fire[i][j]=1;
				q_fire.push({i,j});
			}
			else if(a[i][j]=='J')
			{
				visited[i][j]=1;
				q_jinsoo.push({i,j});
			}
		}
	}
	bfs_fire();
	bfs_jinsoo();
	if(flag) cout<<"IMPOSSIBLE";
}
