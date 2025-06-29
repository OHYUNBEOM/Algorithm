#include<bits/stdc++.h>
using namespace std;
int solution(string s) {
    int answer=0;
    for(int i=0;i<s.size();i++)
    {
        string left = s.substr(0,i);
        string right = s.substr(i);
        string temp=right+left;
        stack<char> stk;
        bool valid=true;
        for(int i=0;i<temp.size();i++)
        {
            if(temp[i]=='(' || temp[i]=='[' || temp[i]=='{')
            {
                stk.push(temp[i]);
            }
            else
            {
                if(stk.empty())
                {
                    valid=false;
                    break;
                }
                if(stk.top()=='(' && temp[i]==')' ||
                stk.top()=='[' && temp[i]==']' ||
                stk.top()=='{' && temp[i]=='}')
                {
                    stk.pop();
                }
                else
                {
                    valid=false;
                    break;
                }
            }
        }
        if(valid && stk.empty()) answer++;
    }
    return answer;
}