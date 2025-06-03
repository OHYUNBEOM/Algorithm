#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int r,c;
char a[1004][1004];
int man_visited[1004][1004];
int fire_visited[1004][1004];
queue<pair<int,int>> man;
queue<pair<int,int>> fire;
void bfs_fire()
{
	while(fire.size())
	{
		int y,x;
		tie(y,x)=fire.front(); fire.pop();
		for(int i=0;i<4;i++)
		{
			int ny=y+dy[i];
			int nx=x+dx[i];
			if(ny<0 || ny>=r || nx<0 || nx>=c || fire_visited[ny][nx] || a[ny][nx]=='#') continue;
			fire_visited[ny][nx]=fire_visited[y][x]+1;
			fire.push({ny,nx});
		}
	}
}
void bfs_man()
{
	while(man.size())
	{
		int y,x;
		tie(y,x)=man.front();man.pop();
		for(int i=0;i<4;i++)
		{
			int ny = y+dy[i];
			int nx = x+dx[i];
			if(ny<0 || ny>=r || nx<0 || nx>=c)
			{
				cout<<man_visited[y][x];
				return;
			}
			if(a[ny][nx]=='#' || man_visited[ny][nx]) continue;
			if(fire_visited[ny][nx] && man_visited[y][x]+1 >= fire_visited[ny][nx]) continue;
			man_visited[ny][nx]=man_visited[y][x]+1;
			man.push({ny,nx});
		}
	}
	cout<<"IMPOSSIBLE";
}
int main()
{
	cin>>r>>c;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			// # : 벽 / . : 지나갈 수 있는 공간 / J : 지훈이의 미로에서 초기 위치(= 지나갈수있는 공간) / F : 불이 난 공간 
			cin>>a[i][j];
			if(a[i][j]=='J') 
			{
				man.push({i,j});
				man_visited[i][j]=1;
				a[i][j]='.';
			}
			if(a[i][j]=='F') 
			{
				fire.push({i,j});
				fire_visited[i][j]=1;
			}
		}
	}
	bfs_fire();
	bfs_man();
} 