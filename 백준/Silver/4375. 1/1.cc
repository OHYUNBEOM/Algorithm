#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while(cin>>s)
	{
		int mod = 1%stoi(s);
		int len=1;
		while(mod!=0)
		{
			mod = (mod*10+1)%stoi(s);
			len++;
		}
		cout<<len<<endl;
	} 
	return 0;
}