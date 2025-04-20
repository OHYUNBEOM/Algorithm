#include<bits/stdc++.h>
using namespace std;
int mid;
string s,s1,s2;
int main()
{
	cin>>s;
	mid=s.size()/2;
	
	s1 = s.substr(0,mid);
	if(s.size()%2==0) s2=s.substr(mid);
	else s2=s.substr(mid+1);
	reverse(s2.begin(),s2.end());

	if(s1==s2) cout<<1;
	else cout<<0;
}