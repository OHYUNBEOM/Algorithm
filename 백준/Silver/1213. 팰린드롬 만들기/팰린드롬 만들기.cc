#include<bits/stdc++.h>
using namespace std;
string s,front,center,behind;
char ch;
map<char,int> mp;
int cnt_2,cnt_3; 
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
			cnt_3++;
			center = it.first;
			it.second--;
		}
		for(int i=0; i<it.second/2;i++)
		{
			front+=it.first;
		}
	}
	if(cnt_3>1)
	{
		cout<<"I'm Sorry Hansoo";
	}
	else
	{
		behind = front;
		reverse(behind.begin(),behind.end());
		cout<<front+center+behind<<"\n";
	}
	return 0;
}