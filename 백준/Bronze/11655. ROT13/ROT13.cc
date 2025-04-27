#include<bits/stdc++.h>
using namespace std;
string s;
vector<char> v;
int main()
{
	getline(cin,s);
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='A' && s[i]<='Z')
		{
			if(s[i]+13>90) v.push_back(s[i]-13);
			else v.push_back(s[i]+13);
		}
		else if(s[i]>='a'&& s[i]<='z')
		{
			if(s[i]+13>122) v.push_back(s[i]-13);
			else v.push_back(s[i]+13);
		}
		else v.push_back(s[i]);
	}
	for(char vv : v)cout<<vv;
}