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
	queue<int> q;
	q.push(n);
	visited[0][n]=1;
	int time=0;
	while(true)
	{
		int brother=k+time*(time+1)/2;
		if(brother>MAX) break;
		
		if(visited[time%2][brother])
		{
			cout<<time<<"\n";
			return 0;
		}
		
		int qsize=q.size();
		for(int i=0;i<qsize;i++)	
		{
			int cur=q.front();q.pop();
			for(int next : {cur+1,cur-1,cur*2})
			{
				if(next<0 || next>MAX) continue;
				
				if(!visited[(time+1)%2][next])
				{
					visited[(time+1)%2][next]=1;
					q.push(next);
				}
			}
		}
		time++;
	}
	cout<<-1<<"\n";
	return 0;
}