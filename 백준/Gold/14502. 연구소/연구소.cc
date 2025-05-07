#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int n,m,ny,nx,max_value;
int a[12][12];
vector<pair<int,int>> v;
void DFS(int y,int x,int a_copy[12][12])
{
	for(int i=0;i<4;i++)
	{
		ny = y + dy[i];
		nx = x + dx[i];
		if(ny<0 || ny>=n || nx<0 || nx>=m) continue;
		if(a_copy[ny][nx]==0)
		{
			a_copy[ny][nx]=2;
			DFS(ny,nx,a_copy);
		}
	}
}
void combi(int start,vector<pair<int,int>> &b)
{
	if(b.size()==3)
	{
		int a_copy[12][12];
		memcpy(a_copy,a,sizeof(a));
		
		for(auto it : b)
		{
			int y = it.first;
			int x = it.second;
			a_copy[y][x] = 1;
		}
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(a_copy[i][j]==2)
				{
					DFS(i,j,a_copy);
				}
			}
		}
		
		int safe=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(a_copy[i][j]==0)
				{
					safe++;
				}
			}
		}
		
		max_value = max(max_value,safe);
		
		return;
	}
	for(int i=start+1;i<v.size();i++)
	{
		b.push_back(v[i]);
		combi(i,b);
		b.pop_back();
	}
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]==0) v.push_back({i,j});
		}
	}
	
	vector<pair<int,int>> vv;
	combi(-1,vv);
	
	cout<<max_value<<"\n";
}