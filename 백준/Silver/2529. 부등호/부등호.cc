#include<bits/stdc++.h>
using namespace std;
int k;
string mx="0",mn="9999999999";
char c[10];
bool visited[10]; // 0 ~ 9
bool oper(int a,int b,char c)
{
	if(c=='<') return a<b;
	else if (c=='>') return a>b;
}
void DFS(int depth,string num)
{
	if(depth==k+1)
	{
		if(num<mn) mn=num;
		if(num>mx) mx=num;
		return;
	}
	for(int i=0;i<=9;i++)
	{
		if(visited[i]) continue;
		if(depth>=1 && !oper(num[depth-1]-'0',i,c[depth-1])) continue;
		visited[i]=true;
		DFS(depth+1,num+to_string(i));
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
	string s="";
	DFS(0,s);
	cout<<mx<<"\n"<<mn;
}