#include<bits/stdc++.h>
using namespace std;
int n;
string s;
map<char,int> mp;
vector<char> c;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		mp[s[0]]++;
	}
	for(auto it : mp)
	{
		if(it.second>=5)
		{
			c.push_back(it.first);
		}
	}
	if(c.size()==0) cout<<"PREDAJA";
	else
	{
		for(char cc : c)cout<<cc;
	}
}
