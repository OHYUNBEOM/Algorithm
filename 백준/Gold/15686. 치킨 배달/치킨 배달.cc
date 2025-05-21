#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int n,m;
int ret=INT_MAX; // 최소값을 찾아야 할 때는 가장 큰값으로 선언할것(min 사용) 
int a[54][54];
int visited[54][54];
vector<pair<int,int>> chicken;
void combi(int start,vector<pair<int,int>> &b)
{
	if(b.size()==m) //폐업시키지 않을 치킨 
	{
		int total_dist=0;
		for(int i=0;i<n;i++) // 집이 있는 위치에서 치킨집까지 가는 거리 계산 
		{
			for(int j=0;j<n;j++)
			{
				if(a[i][j]==1)
				{
					int dist=INT_MAX;
					for(auto it : b)
					{
						dist=min(dist,abs(i-it.first) + abs(j-it.second));
					}
					total_dist+=dist;
				}
			}
		}
		ret=min(ret,total_dist);
		return;
	}
	for(int i=start+1;i<chicken.size();i++)
	{
		b.push_back(chicken[i]);
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
			if(a[i][j]==2) chicken.push_back({i,j}); //치킨집 좌표 저장 
		}
	}
	vector<pair<int,int>> vv;
	combi(-1,vv);
	cout<<ret;
}