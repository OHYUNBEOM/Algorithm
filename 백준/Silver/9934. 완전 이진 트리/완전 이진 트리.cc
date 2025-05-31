#include<bits/stdc++.h>
using namespace std;
int k,n,temp;
vector<int> inorder;
vector<vector<int>> levels;
void dfs(int start, int end, int depth)
{
	if(start>end) return;
	int mid = (start+end)/2;
	levels[depth].push_back(inorder[mid]);
	dfs(start,mid-1,depth+1); // 왼쪽 서브트리 
	dfs(mid+1,end,depth+1); // 오른쪽 서브트리 
}
int main()
{
	cin>>k;
	n=pow(2,k)-1; // 노드 갯수 
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		inorder.push_back(temp); // inorder = node 목록  
	}
	levels.resize(k);
	dfs(0,n-1,0);
	for(int i=0;i<k;i++)
	{
		for(int val : levels[i])
		{
			cout<<val<<" ";
		}
		cout<<"\n";
	}
}