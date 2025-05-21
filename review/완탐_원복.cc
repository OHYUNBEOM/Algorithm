// (0,0) 지점에서 (2,2)로 간다, 방문한 정점 다시 방문 불가능하며 4방향으로 움직임. 맵에 작성된 돈들을 모으는 모든 경우의 수를 출력
#include<bits/stdc++.h>
using namespace std;
const int n = 3;
int a[3][3]={
{10,20,21},
{70,90,12},
{80,110,120}
};
int visited[3][3];
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
vector<int> v;
void print()
{
	for(int i : v) cout<<i<<" ";
	cout<<'\n';
}
void go(int y,int x)
{
	if(y==n-1 && x==n-1) //2,2에 도달했을 때가 기저 조건 
	{
		print();
		return;
	}
	for(int i=0;i<4;i++)
	{
		int ny = y+dy[i];
		int nx = x+dx[i];
		if(ny<0 || ny>=n || nx<0 || nx>=n) continue;
		if(visited[ny][nx]) continue;
		visited[ny][nx]=1;
		v.push_back(a[ny][nx]);
		
		// 완탐 
		go(ny,nx);
		
		// 원복 
		visited[ny][nx]=0;
		v.pop_back();
	}
}
int main()
{
	visited[0][0]=1;
	v.push_back(a[0][0]);
	go(0,0);
	return 0;
}
