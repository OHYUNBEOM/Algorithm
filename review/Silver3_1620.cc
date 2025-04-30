#include <bits/stdc++.h>
using namespace std;
int n,m;
string s;
map<string,int> mp1;
map<int,string> mp2;
vector<string> v;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		mp1[s]=i;
		mp2[i]=s;
	}
	
}
