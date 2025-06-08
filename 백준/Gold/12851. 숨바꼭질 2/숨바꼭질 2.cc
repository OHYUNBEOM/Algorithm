#include<bits/stdc++.h>
using namespace std; 
int n,k;
const int MAX=100000;
int dist[MAX+1];
int cnt[MAX+1];
int main()
{
	cin>>n>>k;
	memset(dist,-1,sizeof(dist));
	dist[n]=0;
	cnt[n]=1;
	queue<int> q;
	q.push(n);
	while(q.size())
	{
		int start=q.front();q.pop();
		for(int next : {start-1,start+1,start*2})
		{
			if(next<0 || next>MAX) continue;
			
			if(dist[next]==-1)
			{
				dist[next] = dist[start]+1;
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