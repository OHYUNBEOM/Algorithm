#include<bits/stdc++.h>
using namespace std;
int n,k;
int dist[100004];
int priv[100004];
int main()
{
	cin>>n>>k;
	memset(dist,-1,sizeof(dist));
	dist[n]=0;
	queue<int> q;
	q.push(n);
	while(q.size())
	{
		int start=q.front();q.pop();
		for(int next : {start+1,start-1,start*2})
		{
			if(next<0 || next>100000) continue;
			if(dist[next]==-1)
			{
				dist[next]=dist[start]+1;
				priv[next]=start;
				q.push(next);
			}
		}
	}
	cout<<dist[k]<<"\n";
	vector<int> v;
	for(int i=k;i!=n;i=priv[i])
	{
		v.push_back(i);
	}
	v.push_back(n);
	reverse(v.begin(),v.end());
	for(int it : v) cout<<it<<" ";
	return 0;
}