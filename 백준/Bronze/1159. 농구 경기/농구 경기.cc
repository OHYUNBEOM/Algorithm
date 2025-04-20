#include<bits/stdc++.h>
using namespace std;
int n,cnt;
string name,result;
vector<string> str;
map<char,int> mapp;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>name;
		mapp[name[0]]++;
	}
	for(auto it : mapp)
	{
		if(it.second>=5)
		{
			result+=it.first;
			cnt++;
		}
	}
	
	if(cnt==0)
	{
		cout<<"PREDAJA";
		exit(0);
	}
	else
	{
		cout<<result;
	}
	return 0;
}