#include<bits/stdc++.h>
using namespace std;
const int MAX=100000;
int dist[MAX+1];
int cnt[MAX+1];
int n,k;
int main()
{
	cin>>n>>k;
	queue<int> q;
	memset(dist,-1,sizeof(dist)); // 방문하지 않은 상태는 -1 
	dist[n]=0; // 시작 위치는 0 
	cnt[n]=1; // 시작 위치에 가만히 있는 경우->이것도 경우로 해석하기 때문에 1로 초기화 하는거임
	q.push(n); //시작점 n에서 시작해서 k로 도달하는거니까.
	while(q.size()) 
	{
		int start=q.front(); q.pop(); // cur : 시작점 정보 
		int cal[3]={-1,1,2};
		int next=0;
		for(int i=0;i<3;i++)
		{
			if(i<2) next=start+cal[i];
			else next=start*cal[i];
			
			if(next<0 || next>MAX) continue;
			
			if(dist[next]==-1) // 방문한적 없으면 
			{
				dist[next]=dist[start]+1; // visited[ny][nx] = visited[y][x]+1; 과 같은 으미로 거리 계산함
				cnt[next]=cnt[start];
				q.push(next);
			}
			else if(dist[next]==dist[start]+1) // 같은 최단시간으로 도착한 경우 
			{
				cnt[next]+=cnt[start];
			}
		}
	}
	cout<<dist[k]<<"\n"<<cnt[k];
}