#include<bits/stdc++.h>
using namespace std;
const int dy[]={-1,0,1,0};
const int dx[]={0,1,0,-1};
int r,c,k,ny,nx,ret;
char a[7][7];
int visited[7][7];
void DFS(int y,int x,int cnt)
{
	if(y==0 && x==c-1)
	{
		if(cnt==k) ret++;
		return;
	}
	visited[y][x]=1;
	for(int i=0;i<4;i++)
	{
		ny=y+dy[i];
		nx=x+dx[i];
		if(ny<0 || ny>=r || nx<0 || nx>=c || visited[ny][nx] || a[ny][nx]=='T') continue;
		DFS(ny,nx,cnt+1);
	}
	visited[y][x]=0;
}
int main()
{
	cin>>r>>c>>k;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cin>>a[i][j];
		}
	}
	DFS(r-1,0,1);
	cout<<ret;
}