#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int t=0;t<n;t++){
        cin>>s;
        stack<char>stk;
        for(char c : s) {
            if(c=='(')
			{
                stk.push(c);
            } 
			else // c == ')'
			{  
                if(!stk.empty()&&stk.top()=='(') 
				{
                	stk.pop();
                } 
				else 
				{
                    stk.push(c);
                }
            }
        }
        cout<<(stk.empty() ? "YES" : "NO") << '\n';
    }
    return 0;
}