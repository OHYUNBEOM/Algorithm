#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int n,m,ret,ny,nx;
char c;
int a[54][54];
int visited[54][54];
vector<pair<int,int>> v;
int BFS(int sy,int sx)
{
	memset(visited,0,sizeof(visited));
	visited[sy][sx]=1;
	queue<pair<int,int>> q;
	q.push({sy,sx});
	int dist=0;
	while(q.size())
	{
		int y,x;
		tie(y,x)=q.front(); q.pop();
		for(int i=0;i<4;i++)
		{
			ny = y+dy[i];
			nx = x+dx[i];
			if(ny<0 || ny>=n || nx<0 || nx>=m || visited[ny][nx] || a[ny][nx]==0) continue;
			visited[ny][nx]=visited[y][x]+1;
			dist=max(dist,visited[ny][nx]-1);
			q.push({ny,nx});
		}
	}
	return dist;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf(" %c",&c);
			if(c=='L') 
			{
				a[i][j]=1;
				v.push_back({i,j});
			}
			else if(c=='W') a[i][j]=0;
		}
	}
	for(auto it : v)
	{
		int dist=BFS(it.first,it.second);
		ret=max(ret,dist);
	}
	printf("%d",ret);
}