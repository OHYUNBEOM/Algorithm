#include<bits/stdc++.h> 
using namespace std;
string s;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	while(true)
	{
		stack<char> stk;
		getline(cin,s);
		if(s==".") break;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='(' || s[i]=='[')
			{
				stk.push(s[i]);	
			}
			else if(s[i]==')')
			{
				if(!stk.empty() && stk.top()=='(')
				{
					stk.pop();
				}
				else
				{
					stk.push(s[i]);
				}
			}
			else if(s[i]==']')
			{
				if(!stk.empty() && stk.top()=='[')
				{
					stk.pop();
				}
				else
				{
					stk.push(s[i]);
				}
			}
		}
		if(stk.size()==0) cout<<"yes"<<"\n";
		else cout<<"no"<<"\n";
	} 
	
	return 0;
}