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
		if(ny<0 || ny>=n || nx<0 || nx>=n || visited[ny][nx]) return false;
	}
	return true;
}
void dfs(int cnt,int sum)
{	
	if(cnt==3)
	{
		ret=min(ret,sum);
		return;
	}
	for(int i=1;i<n-1;i++) // 씨앗은 가장자리에 못심으므로 심을 수 있는 범위는 1 ~ n-1임 
	{
		for(int j=1;j<n-1;j++)
		{
			if(check(i,j)) // 씨앗을 심을 수 있다면, 
			{
				int cost=a[i][j]; // cost 계산 
				visited[i][j]=1;
				for(int k=0;k<4;k++)
				{
					int ny=i+dy[k];
					int nx=j+dx[k];
					visited[ny][nx]=1;
					cost+=a[ny][nx];
				}
				
				dfs(cnt+1,sum+cost);
				
				visited[i][j]=0; // 백트래킹 
				
				for(int k=0;k<4;k++)
				{
					int ny=i+dy[k];
					int nx=j+dx[k];
					visited[ny][nx]=0;
				}
			}
		}
	}
}
int main()
{
	// 씨앗, 꽃잎-> 상하좌우 4방향, 꽃잎이 화단 밖으로 나갈 수 x, 씨앗은 가장자리에는 못심음
	// 꽃 하나당 5평, 5칸에 각각 대여료 있음, 대여료를 최소로 내고 싶을 때 최소 비용 구하기 
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j]; 
		}
	}
	dfs(0,0); // cnt, sum
	cout<<ret;
}
