#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
int arr[15004];
void combi(int start,vector<int> &v)
{
	if(v.size()==2) // 2개 뽑음 
	{
		int a = arr[v[0]];
		int b = arr[v[1]];
		if(a+b==m)
		{
			cnt++;
		}
		return;
	}
	
	for(int i=start+1;i<n;i++)
	{
		v.push_back(i);
		combi(i,v);
		v.pop_back();
	}
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	vector<int> v;
	combi(-1,v);
	cout<<cnt<<"\n";
}

//시간은 378ms로 가장 오래걸림
