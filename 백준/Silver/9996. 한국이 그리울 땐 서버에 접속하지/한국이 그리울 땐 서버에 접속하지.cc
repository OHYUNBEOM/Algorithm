#include<bits/stdc++.h>
using namespace std;
int n,star;
string pattern,prefix,suffix;
vector<string> filename;
int main()
{
	cin>>n>>pattern;
	star = pattern.find('*');
	prefix=pattern.substr(0,star);
	suffix=pattern.substr(star+1);
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		filename.push_back(s);
	}
	for(int i=0;i<filename.size();i++)
	{
		if(filename[i].size()<prefix.size()+suffix.size()) cout<<"NE"<<"\n";
		else if(filename[i].substr(0,prefix.size())==prefix && filename[i].substr(filename[i].size()-suffix.size())==suffix)	
		{
			cout<<"DA"<<"\n";
		}
		else cout<<"NE"<<"\n";
	}
	return 0;
}