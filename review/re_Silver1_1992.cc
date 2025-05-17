#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int a[68][68];
int n;
void DFS(int y,int x,int size)
{
	int val = a[y][x];
	for(int i=y; i<y+size; i++)
	{
		for(int j=x; j<x+size; j++)
		{
			if(val!=a[i][j])
			{
				int half = size/2;
				cout<<'(';
				DFS(y,x,half);
				DFS(y,x+half,half);
				DFS(y+half,x,half);
				DFS(y+half,x+half,half);
				cout<<')';
				return;
			}
		}
	}
	cout<<val;
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
