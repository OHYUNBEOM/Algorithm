#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int r,c,yy1,xx1,yy2,xx2;
char a[1504][1504];
int visited_water[1504][1504];
int visited_swan[1504][1504];
queue<pair<int,int>> swan,next_swan;
queue<pair<int,int>> water;
int day=0;
bool can_meet = false;
void bfs_water()
{
	int qsize=water.size();
	for(int i=0;i<qsize;i++)
	{
		int y,x;
		tie(y,x)=water.front(); water.pop();
		for(int i=0;i<4;i++)
		{
			int ny = y+dy[i];
			int nx = x+dx[i];
			if(ny<0 || ny>=r || nx<0 || nx>=c || visited_water[ny][nx]) continue;
			if(a[ny][nx]=='X')
			{
				a[ny][nx]='.';
				visited_water[ny][nx]=1;
				water.push({ny,nx});
			}
		}
	}
}
void bfs_swan()
{
	while(swan.size())
	{
		int qsize=swan.size();
		for(int i=0;i<qsize;i++)
		{
			int y,x;
			tie(y,x)=swan.front(); swan.pop();
			
			if(y==yy2 && x==xx2) // 목표 swan 좌표에 도달
			{
				can_meet=true;
				return;
			}
			
			for(int i=0;i<4;i++)
			{
				int ny = y+dy[i];
				int nx = x+dx[i];
				if(ny<0 || ny>=r || nx<0 || nx>=c || visited_swan[ny][nx]) continue;
				visited_swan[ny][nx]=1;
				if(a[ny][nx]=='.')
				{
					swan.push({ny,nx});
				}
				else if(a[ny][nx]=='X') // 1턴 뒤 백조가 방문할 좌표 
				{
					next_swan.push({ny,nx});
				}
			}
		}
	}
}
int main()
{
	cin>>r>>c;
	vector<pair<int,int>> v;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cin>>a[i][j];
			if(a[i][j]=='L')
			{
				v.push_back({i,j});
				a[i][j]='.'; // 백조가 있는곳도 곧 물이다. 
				water.push({i,j});
				visited_water[i][j]=1;
			}
			else if(a[i][j]=='.')
			{
				water.push({i,j});
				visited_water[i][j]=1;
			}
		}
	}
	tie(yy1,xx1)=v[0]; // 출발 백조 
	tie(yy2,xx2)=v[1]; // 도착 백조
	
	swan.push({yy1,xx1});
	visited_swan[yy1][xx1]=1;
	
	while(true)
	{
		bfs_swan();
		if(can_meet==true) break;
		bfs_water();
		swan=next_swan;
		next_swan = queue<pair<int,int>>(); // 큐 초기화 -> next_swan은 매번 바뀜 
		day++;
	}
	cout<<day;
	return 0;
}