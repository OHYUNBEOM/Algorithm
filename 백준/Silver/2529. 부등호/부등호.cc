#include<bits/stdc++.h>
using namespace std;
int k;
string mx = "0",mn="99999999999";
char c[10];
bool visited[10];
bool oper(int a,int b,char c)
{
	if(c=='>') return a>b;
	else if(c=='<') return a<b;
}
void DFS(int cnt,string num)
{
	if(cnt==k+1)
	{
		if(mx<num) mx=num;
		if(mn>num) mn=num;
		return;
	}
	for(int i=0;i<=9;i++)
	{
		if(visited[i]) continue;
		if(cnt>=1 && !oper(num[cnt-1]-'0',i,c[cnt-1])) continue;
		if(!visited[i])
		{
			visited[i]=true;
			DFS(cnt+1,num+to_string(i));
			visited[i]=false;
		}
	}
}
int main()
{
	cin>>k;
	for(int i=0;i<k;i++)
	{
		cin>>c[i];	
	}
	DFS(0,"");
	cout<<mx<<"\n"<<mn;
}