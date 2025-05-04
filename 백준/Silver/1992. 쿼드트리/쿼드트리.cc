#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int a[68][68];
int n;
void DFS(int y,int x,int size)
{
	int val=a[y][x];
	bool same = true;
	for(int i=y;i<y+size;i++)
	{
		for(int j=x;j<x+size;j++)
		{
			if(a[i][j]!=val)
			{
				same = false;
				break;
			}
		}
		if(!same) break;
	}
	
	if(same)
	{
		cout<<val;
		return;
	}
	
	int half = size/2;
	cout<<'(';
	DFS(y,x,half);
	DFS(y,x+half,half);
	DFS(y+half,x,half);
	DFS(y+half,x+half,half);
	cout<<')';
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%1d",&a[i][j]);
		}
	}
	DFS(0,0,n);
}