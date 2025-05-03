#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int n,ret,ny,nx;
int mx = -1;
int a[104][104];
int visited[104][104];
vector<int> v;
void DFS(int sy, int sx)
{
	visited[sy][sx]=1;
	for(int i=0;i<4;i++)
	{
		ny = sy + dy[i];
		nx = sx + dx[i];
		if(ny<0 || ny>=n || nx<0 || ny>=n) continue;
		if(a[ny][nx]<=mx) continue;
		if(a[ny][nx]>mx && !(visited[ny][nx]))
		{
			DFS(ny,nx);
		}
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
			mx = max(mx,a[i][j]);
		}
	}
	while(mx--)
	{
		memset(visited,0,sizeof(visited));
		ret=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(a[i][j]>mx && !(visited[i][j]))
				{
					ret++;
					DFS(i,j);
				}
			}
		}
		v.push_back(ret);
	}
	int max_val = *max_element(v.begin(),v.end());
	cout<<max_val<<"\n";
	return 0;
}