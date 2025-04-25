#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
int arr[15004];
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(arr[i]+arr[j]==m)
			{
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}

// 위와 같이 풀수도 있으나, set 조합으로 푼것 대비 11배 속도차이 (88ms / 8ms)
