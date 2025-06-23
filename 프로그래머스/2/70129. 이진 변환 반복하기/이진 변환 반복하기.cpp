#include<bits/stdc++.h>
using namespace std;
int cnt_zero;
string remove_zero(string s)
{
    string result="";
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='0') cnt_zero++;
        else result+=s[i];
    }
    return result;
}
vector<int> solution(string s) {
    int count=0;
    while(s!="1")
    {
        s=remove_zero(s);
        int len=s.size(); // 0 삭제 후 남은 1 갯수 = len, len -> 2진수 변환
        s="";
        while(len>0)
        {
            s=to_string(len % 2) + s;
            len = len/2;
        }
        count++;
    }
    return {count,cnt_zero};
}