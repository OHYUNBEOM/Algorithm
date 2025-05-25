#include<bits/stdc++.h> 
using namespace std;
int n,temp;
vector<int> v;
vector<int> dmg={1,3,9};
int dp[61][61][61];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		v.push_back(temp);
	}
	while(v.size()<3) v.push_back(0);
	queue<tuple<int,int,int>> q;
	q.push(make_tuple(v[0],v[1],v[2]));
	while(q.size())
	{
		int a,b,c;
		tie(a,b,c) = q.front(); q.pop();
		do
		{
			int na=max(0,a-dmg[0]);
			int nb=max(0,b-dmg[1]);
			int nc=max(0,c-dmg[2]);
			if(dp[na][nb][nc]==0)
			{
				dp[na][nb][nc]=dp[a][b][c]+1;
				q.push(make_tuple(na,nb,nc));
			}
		}while(next_permutation(dmg.begin(),dmg.end()));
	}
	cout<<dp[0][0][0];
}
