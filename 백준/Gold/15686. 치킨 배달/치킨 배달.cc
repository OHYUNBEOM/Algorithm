#include<bits/stdc++.h>
using namespace std;
int n,m;
int ret = INT_MAX;
int a[54][54];
vector<pair<int,int>> v;
void combi(int start,vector<pair<int,int>> &b)
{
	if(b.size()==m)
	{
		int total_dist=0;  
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(a[i][j]==1) 
				{
					int dist=INT_MAX;
					for(auto it : b)
					{
						dist=min(dist,abs(i-it.first)+abs(j-it.second));
					}
					total_dist+=dist;
				}
			}
		}
		ret=min(ret,total_dist);
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
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
			if(a[i][j]==2) v.push_back({i,j});
		}
	}
	vector<pair<int,int>> vv;
	combi(-1,vv);
	cout<<ret;
}