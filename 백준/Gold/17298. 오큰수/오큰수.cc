#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>n;
	vector<int> v(n);
	vector<int> ans(n,-1);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	stack<pair<int,int>> stk;
	for(int i=0;i<n;i++)
	{
		while(stk.size() && stk.top().second < v[i])
		{
			ans[stk.top().first]=v[i];
			stk.pop();
		}
		stk.push({i,v[i]});
	}
	for(int i=0;i<n;i++)
	{
		cout<<ans[i]<<" ";
	}
}