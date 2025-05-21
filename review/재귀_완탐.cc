#include<bits/stdc++.h>
using namespace std;
int n,temp,ret;
vector<int> v; 
void combi(int start,vector<int> &b)
{
	int sum=0;
	if(b.size()>=1)
	{
		for(int bb:b)
		{
			sum+=bb;
		}
		ret=max(ret,sum%11);
	}
	for(int i=start+1;i<v.size();i++)
	{
		b.push_back(v[i]);
		combi(i,b);
		b.pop_back();
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		v.push_back(temp);
	}
	vector<int> vv;
	combi(-1,vv);
	cout<<ret;
}


// 예제 입력 ->
// 10
// 24 35 38 40 49 59 60 67 83 98
// 출력 : 10
