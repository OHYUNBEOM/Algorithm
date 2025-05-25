#include<bits/stdc++.h>
using namespace std;
int n=0,ret=INT_MIN;
vector<int> v;
vector<char> c;
string s;
int oper(char c,int a,int b)
{
	if(c=='+') return a+b;
	if(c=='*') return a*b;
	if(c=='-') return a-b;
}
void dfs(int idx,int cur_val)
{
	if(idx==c.size())
	{
		ret=max(ret,cur_val);
		return;
	}
	
	int no=oper(c[idx],cur_val,v[idx+1]);
	dfs(idx+1,no);
	
	if(idx+1<c.size())
	{
		int yes=oper(c[idx+1],v[idx+1],v[idx+2]);
		int ret_yes=oper(c[idx],cur_val,yes);
		dfs(idx+2,ret_yes);
	}
}
int main()
{
	cin>>n>>s;
	for(int i=0;i<n;i++)
	{
		if(isdigit(s[i])) v.push_back(s[i]-'0');
		else c.push_back(s[i]);
	}
	dfs(0,v[0]);
	cout<<ret;
}