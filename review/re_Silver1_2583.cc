#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int m,n,k,x,y,xx,yy,cnt1,cnt2,ny,nx;
vector<int> v;
int a[104][104];
int visited[104][104];
void DFS(int y, int x)
{
	cnt2++;
	visited[y][x]=1;
	for(int i=0;i<4;i++)
	{
		ny = y+dy[i];
		nx = x+dx[i];
		if(ny<0 || ny>=m || nx<0 || nx>=n || visited[ny][nx]) continue;
		if(a[ny][nx]==0)
		{
			DFS(ny,nx);
		}
	}
}
int main()
{
	cin>>m>>n>>k;
	for(int i=0;i<k;i++)
	{
		cin>>x>>y>>xx>>yy;
		for(int i=y;i<yy;i++)
		{
			for(int j=x;j<xx;j++)
			{
				a[i][j]=1;
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i][j]==0 && !visited[i][j])
			{
				cnt1++;
				DFS(i,j);
				v.push_back(cnt2);
				cnt2=0;
			}
		}
	}
	sort(v.begin(),v.end());
	cout<<cnt1<<"\n";
	for(int vv : v) cout<<vv<<" ";
}
