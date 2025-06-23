#include<bits/stdc++.h>
using namespace std;
string answer;
vector<string> str;
string temp="";
string solution(string s) 
{
    for(int i=0;i<s.size();i++)
    {
        temp+=s[i];
        if(s[i]==' ')
        {
            str.push_back(temp);
            temp="";
        }
    }
    if(!temp.empty()) str.push_back(temp);
    
    for(int i=0;i<str.size();i++)
    {
        for(int j=0;j<str[i].size();j++)
        {
            if(j==0)
            {
                char c = toupper(str[i][0]);
                answer+=c;
            }
            else
            {
                char c = tolower(str[i][j]);
                answer+=c;
            }
        }
    }
    return answer;
}