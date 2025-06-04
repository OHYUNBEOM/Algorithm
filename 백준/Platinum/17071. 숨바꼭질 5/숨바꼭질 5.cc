#include<bits/stdc++.h>
using namespace std;
int n,k;
const int MAX=500000;
int visited[2][MAX+1];
int main()
{
	cin>>n>>k;
	if(n==k)
	{
		cout<<0;
		return 0;
	}
	visited[0][n]=1;
	queue<int> q;
	q.push(n);
	int t=0;
	while(true)
	{
		int brother=k+t*(t+1)/2;
		if(brother<0 || brother>MAX) break;
		if(visited[t%2][brother])
		{
			cout<<t;
			return 0;
		}
		int qsize=q.size();
		for(int i=0;i<qsize;i++)
		{
			int start=q.front();q.pop();
			for(int next : {start+1,start-1,start*2})
			{
				if(next<0 || next>MAX) continue;
				if(!visited[(t+1)%2][next])
				{
					visited[(t+1)%2][next]=1;
					q.push(next);
				}
			}
		}
		t++;
	}
	cout<<-1;
}