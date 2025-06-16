#include<bits/stdc++.h>
using namespace std;
int n,ret=INT_MIN;
string s;
vector<int> v;
vector<char> c;
int oper(char op,int a,int b)
{
	if(op=='+') return a+b;
	if(op=='-') return a-b;
	if(op=='*') return a*b;
}
void dfs(int idx,int sum)
{
	if(idx==c.size())
	{
		ret=max(ret,sum);
		return;
	}
	//괄호 x 
	int temp=oper(c[idx],sum,v[idx+1]);
	dfs(idx+1,temp);
	
	// 괄호 o 
	if(idx+1<c.size())
	{
		int temp2=oper(c[idx+1],v[idx+1],v[idx+2]);
		int sum_temp=oper(c[idx],sum,temp2);
		dfs(idx+2,sum_temp);	
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		if(isdigit(s[i])) v.push_back(s[i]-'0');
		else c.push_back(s[i]);
	}
	dfs(0,v[0]); //idx,sum
	cout<<ret;
}
