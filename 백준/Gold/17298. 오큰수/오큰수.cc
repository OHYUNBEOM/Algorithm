#include<bits/stdc++.h>
using namespace std;
int n,temp;
stack<int> stk;
int main()
{
	cin>>n;
	vector<int> v(n);
	vector<int> ans(n,-1);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	for(int i=n-1;i>=0;i--)
	{
		while(stk.size()&&v[stk.top()]<=v[i])
		{
			stk.pop();
		}
		if(stk.size())
		{
			ans[i]=v[stk.top()];
		}
		stk.push(i);
	}
	for(int i=0;i<n;i++)
	{
		cout<<ans[i]<<" ";
	}
}