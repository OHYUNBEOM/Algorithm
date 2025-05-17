#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	cin>>N;
	vector<long long> A(N);
	for(int i=0;i<N;i++)
	{
		cin>>A[i];
	}
	sort(A.begin(),A.end());
	int result=0;
	
	for(int i=0;i<N;i++)
	{
		int left=0;
		int right=N-1;
		while(left<right)
		{
			if(left==i)
			{
				left++;
				continue;
			}
			if(right==i)
			{
				right--;
				continue;
			}
			long long sum = A[left] + A[right];
			
			if(sum==A[i])
			{
				result++;
				break;
			}
			else if(sum<A[i])
			{
				left++;
			}
			else
			{
				right--;
			}
		}
	}
	cout<<result<<"\n";
	return 0;
}