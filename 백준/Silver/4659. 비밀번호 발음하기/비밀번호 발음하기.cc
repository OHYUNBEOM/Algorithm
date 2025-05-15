#include<bits/stdc++.h>
using namespace std;
string s;
int vowel_cnt,con_cnt;
bool is_vowel(char c)
{
	if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return 1;
	else return 0;
}
int main()
{
	while(true)
	{
		cin>>s;
		bool flag=true;
		bool has_vowel=false;
		vowel_cnt=0,con_cnt=0;
		if(s=="end") break;
		for(int i=0;i<s.size();i++)
		{
			if(is_vowel(s[i]))
			{
				has_vowel=true;
				vowel_cnt++;
				con_cnt=0;
			}
			else
			{
				con_cnt++;
				vowel_cnt=0;
			}
			
			//condition 2
			if(vowel_cnt==3 || con_cnt==3) flag=false;
			
			//condition 3
			if(i>=1 && s[i]==s[i-1])
			{
				if(s[i]!='e' && s[i]!='o')
				{
					flag=false;
				}
			}
		}
		//condition 1
		if(has_vowel==false) flag=false;
		
		if(flag==true) cout<<'<'<<s<<"> is acceptable.\n";
		else cout<<'<'<<s<<"> is not acceptable.\n";
	}
}