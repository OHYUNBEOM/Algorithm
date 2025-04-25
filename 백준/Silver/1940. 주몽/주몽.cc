#include<bits/stdc++.h>
using namespace std;
int n,m,x,cnt;
set<int> st;
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		if(st.count(m-x))
		{
			cnt++;
		}
		st.insert(x);
	}
	cout<<cnt;
	return 0;
}