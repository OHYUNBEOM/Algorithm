#include<bits/stdc++.h>
using namespace std;
int k,n;
vector<int> inorder;  
vector<vector<int>> level; // 레벨 별 node , vector<int> inorder가 들어감 
void DFS(int start, int end, int depth)
{
	if(start>end) return;
	int mid=(start+end)/2;
	level[depth].push_back(inorder[mid]);
	// 왼쪽 서브트리 
	DFS(start,mid-1,depth+1);
	// 오른쪽 서브트리
	DFS(mid+1,end,depth+1); 
}
int main()
{
	cin>>k;
	n=pow(2,k)-1;
	level.resize(k);
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		inorder.push_back(temp);
	}
	DFS(0,n-1,0); // start,end,depth
	
	for(int i=0;i<level.size();i++)
	{
		for(int a : level[i])
		{
			cout<<a<<" ";
		}
		cout<<"\n";
	}
	return 0;
}