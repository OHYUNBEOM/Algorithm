#include<bits/stdc++.h>
using namespace std;
int n,ret;
int main()
{
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++)
	{
		int left=0;
		int right=n-1;
		while(left<right)
		{
			if(left==i) {left++; continue;}
			if(right==i) {right--; continue;}
			int sum = v[left]+v[right];
			if(sum==v[i]) {ret++; break;}
			else if(sum<v[i]) left++;
			else right--;
		}
	}
	cout<<ret<<"\n";
}