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
