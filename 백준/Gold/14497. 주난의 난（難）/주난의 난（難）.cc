#include<bits/stdc++.h>
using namespace std;
const int dy[]={-1,0,1,0};
const int dx[]={0,1,0,-1};
int n,m,y,x,y2,x2;
char c[304][304];
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
			int ey,ex;
			tie(ey,ex)=cur.front(); cur.pop();
			for(int i=0;i<4;i++)
			{
				int ny = ey+dy[i];
				int nx = ex+dx[i];	
				if(ny<0 || ny>=n || nx<0 || nx>=m || visited[ny][nx]) continue;
				if(c[ny][nx]=='0' || c[ny][nx]=='#')
				{
					visited[ny][nx]=1;
					cur.push({ny,nx});
				}
				else if(c[ny][nx]=='1')
				{
					visited[ny][nx]=1;
					next.push({ny,nx});
				}
			}
		}
		if(visited[y2-1][x2-1])
		{
			cout<<t;
			return;
		}
		while(next.size())
		{
			int ey,ex;
			tie(ey,ex)=next.front(); next.pop();
			c[ey][ex]='0';
			cur.push({ey,ex});
		}
		t++;
	}
}
int main()
{
	cin>>n>>m>>y>>x>>y2>>x2;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>c[i][j];
		}
	}
	bfs(y-1,x-1);
}