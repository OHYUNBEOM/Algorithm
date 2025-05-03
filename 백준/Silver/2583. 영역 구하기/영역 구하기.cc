#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int m,n,k,ret1,ret2;
int y,x,yy,xx,ny,nx;
vector<int> v;
int a[104][104];
int visited[104][104];
void DFS(int sy,int sx)
{
	visited[sy][sx]=1;
	ret2++;
	for(int i=0;i<4;i++)
	{
		ny = sy + dy[i];
		nx = sx + dx[i];
		if(ny<0 || ny>=m || nx<0 || nx>=n) continue;
		if(a[ny][nx]==0 && !visited[ny][nx])
		{
			DFS(ny,nx); 
		}
	}
	return;
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
				ret2=0;
				DFS(i,j);
				ret1++;
				v.push_back(ret2);
			}
		}
	}
	cout<<ret1<<"\n";
	sort(v.begin(),v.end());
	for(auto it : v)cout<<it<<" ";
}