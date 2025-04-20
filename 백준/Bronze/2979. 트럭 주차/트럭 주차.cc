#include<bits/stdc++.h>
using namespace std;
int A,B,C,total;
vector<pair<int,int>> p(3);
vector<int> t(100,0);
int main()
{
	cin>>A>>B>>C;
	for(int i=0;i<3;i++)
	{
		cin>>p[i].first>>p[i].second;
	}
	for(int i=0;i<3;i++)
	{
		for(int j=p[i].first;j<p[i].second;j++)
		{
			t[j]++;
		}
	}
	for(int i=0;i<100;i++)
	{
		if(t[i]==1)
		{
			total+=t[i]*A;
		}
		else if(t[i]==2)
		{
			total+=t[i]*B;
		}
		else if(t[i]==3)
		{
			total+=t[i]*C;
		}
	}
	cout<<total;
}