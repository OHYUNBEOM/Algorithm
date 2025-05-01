	#include<bits/stdc++.h>
	using namespace std;
	int n,m,cnt;
	vector<int> v;
	void combi(int start, vector<int> &b)
	{
		if(b.size()==2)
		{
			if(v[b[0]]+v[b[1]]==m)
			{
				cnt++;
			}
			return;	
		}
		for(int i=start+1; i<n; i++)
		{
			b.push_back(i);
			combi(i,b);
			b.pop_back();
		}
	}
	int main()
	{
		cin>>n>>m;
		for(int i=0;i<n;i++)
		{
			int nn;
			cin>>nn;
			v.push_back(nn);
		}
		vector<int> a;
		combi(-1,a);
		cout<<cnt;
	}
