#include<bits/stdc++.h>
using namespace std;
const int dy[]={-1,0,1,0};
const int dx[]={0,1,0,-1};
int t,n,m,k,y,x,cnt;
int a[54][54];
int visited[54][54];
vector<int> v;
void DFS(int y,int x)
{
	visited[y][x]=1;
	for(int i=0;i<4;i++)
	{
		int ny=y+dy[i];
		int nx=x+dx[i];
		if(ny<0 || ny>=n || nx<0 || nx>=m || visited[ny][nx]) continue;
		if(!visited[ny][nx] && a[ny][nx]==1)
		{
			DFS(ny,nx);
		}
	}
}
int main()
{
	cin>>t;
	for(int i=0;i<t;i++)
	{
		memset(a,0,sizeof(a));
		memset(visited,0,sizeof(visited));
		cnt=0;
		cin>>n>>m>>k;
		for(int i=0;i<k;i++)
		{
			cin>>y>>x;
			a[y][x]=1;
		}
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(!visited[i][j] && a[i][j]==1)
				{
					cnt++;
					DFS(i,j);
				}
			}
		}
		v.push_back(cnt);
	}
	for(int vv : v) cout<<vv<<"\n";
}
