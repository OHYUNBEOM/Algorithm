#include<bits/stdc++.h>
using namespace std;
int n,a,ret;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		ret=0;
		for(int i=5;i<=a;i*=5)
		{
			ret+=a/i;
		}
		cout<<ret<<"\n";
	}
}
