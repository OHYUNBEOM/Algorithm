#include<bits/stdc++.h>
using namespace std;
int h,w,idx;
char a[104][104];
int b[104][104];
string s;
int main()
{
	cin>>h>>w;
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=0;i<h;i++)
	{
		idx=-1;
		for(int j=0;j<w;j++)
		{
			if(a[i][j]=='c')
			{
				idx=j;
				b[i][j]=0;
			}
			else if(idx==-1)
			{
				b[i][j]=-1;
			}
			else
			{
				b[i][j]=j-idx;
			}
		}
	}
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			cout<<b[i][j]<<" ";
		}
		cout<<"\n";
	}
}