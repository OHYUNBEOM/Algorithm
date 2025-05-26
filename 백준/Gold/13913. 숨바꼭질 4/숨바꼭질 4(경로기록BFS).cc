#include<bits/stdc++.h>
using namespace std; 
int n,k;
const int MAX=100000;
int dist[MAX+1]; // 최단 거리를 위함 
int prevNode[MAX+1];
int main()
{
	cin>>n>>k;
	memset(dist,-1,sizeof(dist));
	dist[n]=0;
	prevNode[n]=-1;
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
				dist[next]=dist[start]+1;
				prevNode[next]=start;
				q.push(next);
			}
		}
	}
	cout<<dist[k]<<"\n";
	vector<int> v;
	for(int i=k;i!=-1;i=prevNode[i])
	{
		v.push_back(i);
	}
	reverse(v.begin(),v.end());
	for(int vv : v)cout<<vv<<" ";
}
