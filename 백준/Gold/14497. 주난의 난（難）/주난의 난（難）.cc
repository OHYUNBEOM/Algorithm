#include<bits/stdc++.h>
using namespace std;
const int dy[]={-1,0,1,0};
const int dx[]={0,1,0,-1};
int n,m,ny,nx;
char c[304][304];
int visited[304][304];
int x11,y11,x22,y22;
void BFS(int sy,int sx)
{
	queue<pair<int,int>> cur,next;
	cur.push({sy,sx});
	visited[sy][sx]=1;
	int turn=1;
	while(true)
	{
		while(cur.size())
		{
			int y,x;
			tie(y,x)=cur.front();cur.pop();
			for(int i=0;i<4;i++)
			{
				ny = y+dy[i];
				nx = x+dx[i];
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
		if(visited[y22-1][x22-1])
		{
			cout<<turn;
			return;
		}
		while(next.size())
		{
			int y,x;
			tie(y,x) = next.front();next.pop();
			c[y][x]='0';
			cur.push({y,x});
		}
		turn++;
	}
}
int main()
{
   cin>>n>>m>>y11>>x11>>y22>>x22;
   for(int i=0;i<n;i++)
   {
      for(int j=0;j<m;j++)
      {
         cin>>c[i][j];
      }
   }
   BFS(y11-1,x11-1);
}