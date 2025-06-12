#include<bits/stdc++.h>
using namespace std;
const int dy[]={-1,0,1,0};
const int dx[]={0,1,0,-1};
int n,l,r,ret;
int a[54][54];
int visited[54][54];
vector<pair<int,int>> united;
void go(int y,int x)
{
	visited[y][x]=1;
	united.push_back({y,x});
	for(int i=0;i<4;i++)
	{
		int ny=y+dy[i];
		int nx=x+dx[i];
		if(ny<0 || ny>=n || nx<0 || nx>=n || visited[ny][nx]) continue;
		int diff=abs(a[y][x]-a[ny][nx]);
		if(diff>=l && diff<=r)
		{
			go(ny,nx);
		}
	}
}
int main()
{
	cin>>n>>l>>r;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	while(true)
	{
		bool flag=true;
		memset(visited,0,sizeof(visited));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(!visited[i][j])
				{
					united.clear();
					go(i,j);
					if(united.size()>1)
					{
						flag=false;
						int sum=0,avg=0;
						for(auto it : united)
						{
							sum+=a[it.first][it.second];
						}
						avg=sum/united.size();
						for(auto it : united)
						{
							a[it.first][it.second]=avg;
						}	
					}
				}
			}
		}
		if(flag) break;
		else ret++;
	}
	cout<<ret;
}
