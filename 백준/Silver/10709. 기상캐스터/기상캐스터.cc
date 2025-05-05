#include<bits/stdc++.h>
using namespace std;
int h,w,cnt,idx;
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
		cnt=0,idx=0;
		s="";
		for(int j=0;j<w;j++)
		{
			s+=a[i][j];
			if(s.find('c')==string::npos)
			{
				b[i][j]=-1;
			}
			if(a[i][j]=='c')
			{
				b[i][j]=0;
			}
			if(a[i][j]=='.')
			{
				cnt++;
				if(j==0) b[i][j]=-1;
				for(int k=0;k<s.size();k++)
				{
					if(s[k]=='c')
					{
						idx=k;
					}
				}
				if(s.find('c')!=string::npos && s.find('c')<j)
				{
					b[i][j] = j-idx;
				}
			}
		}
		if(cnt==w)
		{
			for(int j=0;j<w;j++)
			{
				b[i][j]=-1;
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