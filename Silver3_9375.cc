#include <bits/stdc++.h>
using namespace std;
int tc,n;
string a,b;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>tc;
	for(int i=0;i<tc;i++)
	{
		cin>>n;
		map<string,int> mp;
		for(int i=0;i<n;i++)
		{
			cin>>a>>b;
			mp[b]++;
		}
		int ret = 1;
		for(auto it : mp)
		{
			ret*=(it.second+1);
		}
		cout<<ret-1<<"\n";
	}
	return 0;
}
