#include<bits/stdc++.h>
using namespace std;
string s;
string v = "aeiou";
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
		if(s=="end") break;
		bool acceptable=true;
		bool has_vowel=false;
		int a=0,b=0;
		for(int i=0;i<s.size();i++)
		{
			char ss = s[i];
			// condition 1
			if(is_vowel(ss))
			{
				has_vowel=true;
				a++;
				b=0;
			}
			else
			{
				b++;
				a=0;
			}
			

			// condition 2
			if(a==3 || b==3)
			{
				acceptable=false;
				break;
			}
			
			// condition 3
			if(i>=1 && s[i] == s[i-1])
			{
				if(s[i]!='e' && s[i]!='o')
				{
					acceptable=false;
					break;
				}
			}
		}
		if(!has_vowel) acceptable = false;
		
		if(acceptable) cout<<"<"<<s<<"> is acceptable.\n";
		else cout<<"<"<<s<<"> is not acceptable.\n";
	}
}