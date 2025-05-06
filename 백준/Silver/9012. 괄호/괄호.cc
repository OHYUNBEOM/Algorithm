#include<bits/stdc++.h>
using namespace std;
int n;
string s;
string tp;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		stack<string> stk;
		stk.push(string(1,s[0]));
		for(int i=1;i<s.size();i++)
		{
			if(!stk.empty() && stk.top() + string(1,s[i]) == "()")
			{
				stk.pop();
			}
			else stk.push(string(1,s[i]));
		}
		if(stk.size()==0) cout<<"YES"<<"\n";
		else cout<<"NO"<<"\n";
	}
}