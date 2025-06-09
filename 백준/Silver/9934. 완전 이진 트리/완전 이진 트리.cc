#include<bits/stdc++.h>
using namespace std;
int k;
vector<int> node;
vector<vector<int>> level;
void dfs(int start,int end,int depth)
{
	if(start>end) return;
	int mid=(start+end)/2;
	level[depth].push_back(node[mid]);
	dfs(start,mid-1,depth+1);
	dfs(mid+1,end,depth+1);
}
int main()
{
	cin>>k;
	int n=pow(2,k)-1;
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		node.push_back(temp);
	}
	level.resize(k);
	dfs(0,n-1,0);
	for(int i=0;i<k;i++)
	{
		for(auto it : level[i])
		{
			cout<<it<<" ";
		}
		cout<<"\n";
	}
}