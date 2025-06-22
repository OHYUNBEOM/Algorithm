#include<bits/stdc++.h>
using namespace std;
const int dy[]={-1,0,1,0};
const int dx[]={0,1,0,-1};
int n,m,y,x,yy,xx,ret;
char a[304][304];
int visited[304][304];
void bfs(int sy,int sx)
{
	visited[sy][sx]=1;
	queue<pair<int,int>> cur,next;
	cur.push({sy,sx});
	int t=1;
	while(true)
	{
		while(cur.size())
		{
			int y,x;
			tie(y,x)=cur.front();cur.pop();
			for(int i=0;i<4;i++)
			{
				int ny=y+dy[i];
				int nx=x+dx[i];
				if(ny<0 || ny>=n || nx<0 || nx>=m || visited[ny][nx]) continue;
				if(a[ny][nx]=='0' || a[ny][nx]=='#')
				{
					cur.push({ny,nx});
					visited[ny][nx]=1;
				}
				else if(a[ny][nx]=='1')
				{
					next.push({ny,nx});
					visited[ny][nx]=1;
				}
			}
		}
		if(visited[yy-1][xx-1])
		{
			cout<<t;
			return;
		}
		while(next.size())
		{
			int y,x;
			tie(y,x)=next.front();next.pop();
			cur.push({y,x});
			a[y][x]='0';
		}
		t++;
	}
}
int main()
{
	cin>>n>>m>>y>>x>>yy>>xx;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}
	bfs(y-1,x-1);
}