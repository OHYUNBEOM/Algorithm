#include<bits/stdc++.h>
using namespace std;
map<int,int> m1,m2;
int n,c,a;
vector<int> v;
bool cmp(int a,int b)
{
	if(m1[a]!=m1[b]) return m1[a]>m1[b];
	return m2[a]<m2[b];
}
int main()
{
	cin>>n>>c;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		v.push_back(a);
		m1[a]++; 
		if(m2.count(a)==0) m2[a]=i;
	}
	sort(v.begin(),v.end(),cmp);
	for(int vv:v) cout<<vv<<" ";
}