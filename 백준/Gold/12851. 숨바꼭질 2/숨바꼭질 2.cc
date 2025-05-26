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
	memset(dist,-1,sizeof(dist));
	dist[n]=0;
	cnt[n]=1;
	q.push(n);
	while(q.size()) 
	{
		int start=q.front(); q.pop();
		int next=0;
		for(int next : {start-1,start+1,start*2})
		{
			if(next<0 || next>MAX) continue;
			
			if(dist[next]==-1)
			{
				dist[next]=dist[start]+1;
				cnt[next]+=cnt[start];
				q.push(next);
			}
			else if(dist[next]==dist[start]+1)
			{
				cnt[next]+=cnt[start];
			}
		}
	}
	cout<<dist[k]<<"\n"<<cnt[k];
}