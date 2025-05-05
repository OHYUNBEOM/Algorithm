#include<bits/stdc++.h>
using namespace std;
int n,f,cnt;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cnt=0;	
		cin>>f;
		for(int i=5;f/i>0;i*=5)
		{
			cnt+=f/i;
		}
		cout<<cnt<<"\n";
	}
}