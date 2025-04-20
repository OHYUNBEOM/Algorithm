#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> v;
int main()
{
	cin>>s;
	for(char i='a';i<='z';i++)
	{
		int cnt=0;
		for(int j=0;j<s.size();j++)
		{
			if(s[j]==i)
			{
				cnt++;
			}
		}
		v.push_back(cnt);
	}
	for(int bb:v)cout<<bb<<" ";
	return 0;
}