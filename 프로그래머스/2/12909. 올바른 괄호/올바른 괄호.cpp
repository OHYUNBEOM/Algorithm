#include<bits/stdc++.h>
using namespace std;
bool solution(string s)
{
    stack<char> stk;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(') stk.push(s[i]);
        else
        {
            if(!stk.empty() && stk.top()=='(')
            {
                stk.pop();
            }
            else
            {
                return false;
            }
        }
    }
    if(stk.empty()) return true;
    else return false;
}