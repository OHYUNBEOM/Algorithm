#include<bits/stdc++.h>
using namespace std;
string s;
char temp;
vector<char> ch;
int main()
{
	getline(cin,s);
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='a'&&s[i]<='z')
		{
			if(s[i]+13>122)
			{
				ch.push_back(char(s[i]+13-26));
			}
			else
			{
				ch.push_back(char(s[i]+13));
			}
		}
		else if(s[i]>='A'&&s[i]<='Z')
		{
			if(s[i]+13>90)
			{
				ch.push_back(char(s[i]+13-26));	
			}
			else
			{
				ch.push_back(char(s[i]+13));
			}
		}
		else
		{
			ch.push_back(char(s[i]));
		}
	}
	for(char cc : ch)cout<<cc;
	return 0;
}