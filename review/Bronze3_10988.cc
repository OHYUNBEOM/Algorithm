#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	cin>>s;
	string temp = s;
	reverse(temp.begin(),temp.end());
	if(s==temp) cout<<1;
	else cout<<0;
}
