#include<bits/stdc++.h>
using namespace std;
vector<string> v;
int mx=INT_MIN,mn=INT_MAX;
string temp="";
string solution(string s) {
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==' ')
        {
            v.push_back(temp);
            temp="";
        }
        else
        {
            temp+=s[i];
        }
    }
    v.push_back(temp);
    
    for(string vv : v)
    {
        if(stoi(vv))
        {
            mn=min(mn,stoi(vv));
            mx=max(mx,stoi(vv));
        }
    }
    string answer=to_string(mn)+" "+to_string(mx);
    return answer;
}