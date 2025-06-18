#include<bits/stdc++.h>
using namespace std;
int n,k;
int dist[100004];
int cnt[100004];
int main()
{
	cin>>n>>k;
	memset(dist,-1,sizeof(dist)); // 방문하지 않은 곳은 -1로 초기화 
	dist[n]=0; // 출발점, 거리를 나타내는 dist 배열에 해당 좌표는 출발점이니 0 
	cnt[n]=1; // 같은 거리로 k에 도착하는 방법을 담을 cnt 배열, 출발 위치도 카운팅해야하므로 1 
	queue<int> q;
	q.push(n); // 시작 지점 queue에 push
	while(q.size())
	{
		int start=q.front();q.pop();
		for(int next : {start+1,start-1,start*2}) // start에서 시작, +1,-1,*2로 이동 
		{
			if(next<0 || next>100000) continue;
			if(dist[next]==-1)  // next 지점이 아직 방문하지 않은 위치라면
			{
				dist[next]=dist[start]+1; // dist[start]에서 1초 후를 의미
				cnt[next]+=cnt[start]; // 방법 카운팅 
				q.push(next) ;
			}
			else if(dist[next]==dist[start]+1) // 다음에 방문하는 곳이 이미 들린 곳이면
			{
				cnt[next]+=cnt[start];
			} 
		}
	}
	cout<<dist[k]<<"\n"<<cnt[k];
}
