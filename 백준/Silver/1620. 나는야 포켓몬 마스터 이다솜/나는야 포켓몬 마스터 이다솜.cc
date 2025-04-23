#include<bits/stdc++.h>
using namespace std;
int n,m;
unordered_map<int,string> poket;
unordered_map<string,int> reverse_poket;
vector<string> str;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		poket[i]=s;
		reverse_poket[s]=i;
	}
	for(int i=0;i<m;i++)
	{
		string s1;
		cin>>s1;
		str.push_back(s1);
	}
	
	for(int j=0;j<m;j++)
	{
		if(atoi(str[j].c_str())!=0)
		{
			cout<<poket[atoi(str[j].c_str())]<<"\n";
		}
		else
		{
			cout<<reverse_poket[str[j]]<<"\n";
		}
	}
	return 0;
}