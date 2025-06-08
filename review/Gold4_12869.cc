#include<bits/stdc++.h>
using namespace std;
int n,temp;
vector<int> v; 
int dp[61][61][61];
vector<int> dmg={1,3,9};
int main()
{
	// SCV 공격 : 9 -> 3 -> 1
	// 체력 0 or 이하 : 파괴
	// SCV 체력이 주어졌을 때, 모든 SCV를 파괴하기 위한 횟수의 최소값
	// SCV : 1 ~ 3 
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		v.push_back(temp);
	}
	while(v.size()<3)
	{
		v.push_back(0); // SCV 3개를 기준 
	}
	queue<tuple<int,int,int>> q;
	q.push(make_tuple(v[0],v[1],v[2])); // q에 최초 체력 3개가 들어감.
	while(q.size())
	{
		int a,b,c;
		tie(a,b,c)=q.front();q.pop();
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
