#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
int main()
{
	for(int i=0;i<9;i++)
	{
		cin>>n;
		v.push_back(n);
	}
	sort(v.begin(),v.end());
	do
	{
		int sum=0;
		for(int i=0; i<7; i++)
		{
			sum+=v[i];
		}
		if(sum==100)
		{
			for(int i=0; i<7; i++)
			{
				cout<<v[i]<<"\n";
			}
			return 0;
		}
	}while(next_permutation(v.begin(),v.end()));
	return 0;
}