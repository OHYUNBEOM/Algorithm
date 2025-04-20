#include<bits/stdc++.h>
using namespace std;
//int n;
vector<int> v(9);
void combi(int start,vector<int> &b)
{	
	int sum=0;
	if(b.size()==7)
	{
		for(int i=0;i<7;i++)
		{
			sum+=b[i];
			if(sum==100)
			{
				for(int cc:b)cout<<cc<<"\n";
				exit(0);
			}
		}
	}
	for(int i=start+1;i<9;i++)
	{
		b.push_back(v[i]);
		combi(i,b);
		b.pop_back();
	}
	return;
}
int main()
{
	vector<int> a;
	for(int i=0;i<9;i++)
	{
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	combi(-1,a);
	return 0;
}
