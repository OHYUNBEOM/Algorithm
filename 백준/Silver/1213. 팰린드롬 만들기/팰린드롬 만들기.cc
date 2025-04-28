#include <bits/stdc++.h>
using namespace std;
int cnt;
string s,first,second,middle;
map<char,int> mp;
int main()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		mp[s[i]]++;
	}
	for(auto it : mp)
	{
		if(it.second%2==1)
		{
			cnt++;
			middle=it.first;
		}
		for(int i=0;i<it.second/2;i++)
		{
			first+=it.first;
		}
	}
	second = first;
	reverse(second.begin(),second.end());
	if(cnt>1)cout<<"I'm Sorry Hansoo";
	else cout<<first+middle+second;
}