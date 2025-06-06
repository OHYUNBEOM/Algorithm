#include<bits/stdc++.h>
using namespace std;
int k;
char c[10];
string mx="0",mn="99999999999";
bool visited[10];
bool oper(int a,int b,char cc)
{
	if(cc=='>') return a>b;
	else if(cc=='<') return a<b;
}
void dfs(int idx,string s)
{
	if(idx==k+1)
	{
		if(mx<s) mx=s;
		if(mn>s) mn=s;
		return;
	}
	for(int i=0;i<=9;i++)
	{
		if(visited[i]) continue;
		if(idx>=1 && !oper(s[idx-1]-'0',i,c[idx-1])) continue;
		visited[i]=true;
		dfs(idx+1,s+to_string(i));
		visited[i]=false;
	}
}
int main()
{
	cin>>k;
	for(int i=0;i<k;i++)
	{
		cin>>c[i];
	}
	dfs(0,"");
	cout<<mx<<"\n"<<mn;
}