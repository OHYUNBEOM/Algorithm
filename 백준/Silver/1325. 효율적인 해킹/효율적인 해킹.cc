#include<bits/stdc++.h>
using namespace std;
int n,m,a,b;
vector<int> adj[10004];
int visited[10004];
int dfs(int here)
{
	visited[here]=1;
	int cnt=1;
	for(int there : adj[here])
	{
		if(!visited[there])
		{
			cnt+=dfs(there);
		}
	}
	return cnt;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		adj[b].push_back(a); //b->a
	}
	int max_cnt=0;
	vector<int> ret;
	for(int i=1;i<=n;i++)
	{
		memset(visited,0,sizeof(visited));
		int cnt=dfs(i);
		
		if(cnt>max_cnt)
		{
			max_cnt=cnt;
			ret.clear();
			ret.push_back(i);
		}
		else if(cnt==max_cnt)
		{
			ret.push_back(i);
		}
	}
	
	for(int xx : ret) cout<<xx<<" ";
}