#include<bits/stdc++.h>
using namespace std;
int n,k,temp,psum[100001];
int ret = -100004;
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>temp;
		psum[i]=psum[i-1]+temp; //구간합 배열 생성
	}
	for(int i=k;i<=n;i++)
	{
		ret = max(ret,psum[i] - psum[i-k]);
	} 
	cout<<ret;
}
