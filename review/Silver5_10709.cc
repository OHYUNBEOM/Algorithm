#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
char c[104][104];
int a[104][104];
int n,m,priv;
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>c[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		priv=-1;
		for(int j=0;j<m;j++)
		{
			if(c[i][j]=='c')
			{
				a[i][j]=0;
				priv=j;
			}
			else if(c[i][j]=='.')
			{
				if(priv==-1)
				{
					a[i][j]=-1;
				}
				else
				{
					a[i][j]=j-priv;
				}
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
}
