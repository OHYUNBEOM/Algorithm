#include <bits/stdc++.h>
using namespace std;
int n,m;
string s,x;
map<string,int> mp1;
map<int,string> mp2;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		mp1[s]=i;
		mp2[i]=s;
	}
	for(int i=0;i<m;i++)
	{
		cin>>x;
		if(atoi(x.c_str())==0)
		{
			cout<<mp1[x]<<"\n";
		}
		else
		{
			cout<<mp2[atoi(x.c_str())]<<"\n";
		}
	}
}
