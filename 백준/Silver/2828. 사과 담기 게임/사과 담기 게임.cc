#include<bits/stdc++.h>
using namespace std;
int n,m,j,dis,diff;
int arr[24];
int l=1;
int main()
{
	cin>>n>>m>>j;
	int r=m;
	for(int i=0;i<j;i++)
	{
		cin>>arr[i];
	}
	for(int i=0;i<j;i++)
	{
		if(arr[i]>=l&&arr[i]<=r) continue;
		if(arr[i]>r)
		{
			diff=abs(arr[i]-r);
			dis+=diff;
			l+=diff;
			r+=diff;
		}
		if(arr[i]<l)
		{
			diff=abs(arr[i]-l);
			dis+=diff;
			l-=diff;
			r-=diff;
		}
	}
	cout<<dis;
}