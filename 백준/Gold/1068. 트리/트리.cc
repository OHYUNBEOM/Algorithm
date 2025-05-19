#include<bits/stdc++.h>
using namespace std;
int n,remove_node,node,root;
vector<int> adj[54];
int dfs(int here)
{
	int ret=0;
	int child=0;
	for(int there : adj[here])
	{
		if(there==remove_node) continue;
		ret+=dfs(there);
		child++;
	}
	if(child==0) return 1;
	return ret;
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>node;
		if(node==-1) root=i;
		else adj[node].push_back(i);
	}
	cin>>remove_node;
	if(remove_node==root) cout<<0;
	else cout<<dfs(root);
}