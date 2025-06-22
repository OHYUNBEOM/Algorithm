#include<bits/stdc++.h>
using namespace std;
int n,m,h,ret=INT_MAX;
int visited[34][34];
bool check()
{
	// 세로 줄을 기준으로 시작과 끝이 같은지 확인
	for(int i=1;i<=n;i++)
	{
		int start=i;
		for(int j=1;j<=h;j++)
		{
			if(visited[j][start]) start++;
			else if(visited[j][start-1]) start--;
		}
		if(start!=i) return false;
	} 
	return true;
}
void go(int here,int cnt) // here : 가로 줄, cnt : 추가되는 가로줄 
{
	if(cnt>3) return;
	if(check())
	{
		ret=min(ret,cnt);
		return;
	}
	for(int i=here;i<=h;i++)
	{
		for(int j=1;j<n;j++)
		{
			if(visited[i][j] || visited[i][j-1] || visited[i][j+1]) continue;
			visited[i][j]=1;
			go(i,cnt+1);
			visited[i][j]=0;
		}
	}
}
int main()
{
	cin>>n>>m>>h;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		visited[a][b]=1;
	}
	go(1,0);
	if(ret==INT_MAX) cout<<-1;
	else cout<<ret;
}



//✅ 동작 순서 요약
//처음엔 가로선을 하나도 추가하지 않은 상태에서 시작합니다 (cnt = 0)

//check() 호출:

//이미 조건을 만족하면 (모든 세로선이 자기 자신으로 내려가면) → 종료

//조건을 못 만족하면:
//가능한 모든 위치에 대해 가로선을 하나 추가해보고
//다시 check()를 호출해서 조건을 만족하는지 확인

//안되면 → 2개 추가해서 재귀

//그래도 안되면 → 3개까지 추가해서 재귀

//3개까지 다 해도 안되면 → 종료

//→ 즉, 최대 3개까지 조합 가능한 모든 가로선 추가 위치를 탐색하며
//조건을 만족하는 가장 빠른 경우를 찾는 구조
