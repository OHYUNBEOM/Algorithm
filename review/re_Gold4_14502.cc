#include<bits/stdc++.h>
using namespace std;
const int dy[]={-1,0,1,0};
const int dx[]={0,1,0,-1};
int n,m,ret;
int a[10][10];
int a_copy[10][10];
int visited[10][10];
vector<pair<int,int>> v;
void DFS(int y,int x)
{
	visited[y][x]=1;
	for(int i=0;i<4;i++)
	{
		int ny=y+dy[i];
		int nx=x+dx[i];
		if(ny<0 || ny>=n || nx<0 || nx>=m || visited[ny][nx] || a_copy[ny][nx]==1) continue;
		if(a_copy[ny][nx]==0) // 바이러스와 인접한 안전 영역에 
		{
			visited[ny][nx]=1;
			a_copy[ny][nx]=2; // 바이러스를 퍼뜨림 
			DFS(ny,nx);
		}
	}
}
void combi(int start, vector<pair<int,int>> &b)
{
	if(b.size()==3) // 벽 3개를 세웠을 때 
	{
		int cnt=0;
		memcpy(a_copy,a,sizeof(a)); // 매번 벽을 세울때마다 확인해보려고 만든 복사본 배열 
		for(auto it : b) // 벽을 세울 후보 3군데 
		{
			a_copy[it.first][it.second]=1; // 벽 세우기 
		}
		
		memset(visited,0,sizeof(visited));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(a_copy[i][j]==2) // 바이러스 위치에서 탐색 시작 
				{
					DFS(i,j);
				}
			}
		}
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(a_copy[i][j]==0) // 바이러스 다 퍼뜨린 후에도 안전 영역 카운팅 
				{
					cnt++;
				}
			}
		}
		ret=max(ret,cnt);
		return;
	}
	for(int i=start+1;i<v.size();i++) // 빈칸인 영역 중에서 뽑아야 함 
	{
		b.push_back(v[i]); // 빈칸 후보들중에서 3개 뽑는 경우 모두 체크할것 
		combi(i,b);
		b.pop_back();
	}
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]==0) v.push_back({i,j}); // 안전 영역 저장 
		}
	}
	vector<pair<int,int>> vv;
	combi(-1,vv); // combi 재귀 함수 호출 
	cout<<ret;
}
