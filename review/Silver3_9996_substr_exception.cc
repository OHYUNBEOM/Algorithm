#include<bits/stdc++.h>
using namespace std;
int n;
string pattern,prefix,suffix,filename;
vector<string> v;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> pattern;
	int index = pattern.find('*');
	prefix = pattern.substr(0,index);
	suffix = pattern.substr(index+1);
	for(int i=0; i<n; i++)
	{
		cin >> filename;
		v.push_back(filename);
	}
	for(int i=0; i<v.size(); i++)
	{
		if((v[i].size()>=prefix.size()+suffix.size()) && v[i].substr(0,prefix.size())==prefix && v[i].substr(v[i].size()-suffix.size())==suffix)
		{
			cout << "DA" << "\n";	
		} 
		else cout << "NE" << "\n";
	}
}
