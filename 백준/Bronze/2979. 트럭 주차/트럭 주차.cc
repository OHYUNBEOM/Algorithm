#include<bits/stdc++.h>
using namespace std;
int arr[100];
int a,b,c,x,y,sum;
int main()
{
	cin>>a>>b>>c;
	for(int i=0;i<3;i++)
	{
		cin>>x>>y;
		for(int i=x;i<y;i++)
		{
			arr[i]++;
		}
	}
	
	for(int array : arr)
	{
		if(array==1) sum+=array*a;
		else if(array==2) sum+=array*b;
		else if(array==3) sum+=array*c; 
	}
	cout<<sum;
}