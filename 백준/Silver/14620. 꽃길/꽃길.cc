#include<bits/stdc++.h>
using namespace std;
const int dy[]={-1,0,1,0};
const int dx[]={0,1,0,-1};
int n,ret=INT_MAX;
int a[12][12];
int visited[12][12];
bool check(int y,int x)
{
	if(visited[y][x]) return false;
	for(int i=0;i<4;i++)
	{
		int ny=y+dy[i];
		int nx=x+dx[i];
		if(ny<0 || ny>=n || nx<0 || nx>=n) return false;
		if(visited[ny][nx]) return false;
	}
	return true;
}
void go(int cnt,int sum)
{
	if(cnt==3)
	{
		ret=min(ret,sum);
		return;
	}
	for(int i=1;i<n-1;i++)
	{
		for(int j=1;j<n-1;j++)
		{
			if(check(i,j))
			{
				visited[i][j]=1;
				int cost=a[i][j];
				for(int k=0;k<4;k++)
				{
					int ny=i+dy[k];
					int nx=j+dx[k];
					visited[ny][nx]=1;
					cost+=a[ny][nx];
				}
				
				go(cnt+1,sum+cost);
				
				visited[i][j]=0;
				for(int k=0;k<4;k++)
				{
					int ny = i+dy[k];
					int nx = j+dx[k];
					visited[ny][nx]=0;
				}	
			}
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
		}
	}
	go(0,0);
	cout<<ret;
}