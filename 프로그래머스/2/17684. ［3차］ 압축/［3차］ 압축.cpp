#include<bits/stdc++.h>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string,int> mp;
    for(int i=0;i<26;i++)
    {
        char c = 'A'+i;
        string s = "";
        s+=c;
        mp[s]=i+1;
    }
    
    int pos=0; // 현재 위치
    while(pos<msg.length())
    {
        string w="";
        int len=0;
        while(pos+len<msg.length() && mp.count(msg.substr(pos,len+1))) // mp에서 가장 긴 문자열 찾기
        {
            len++;
            w=msg.substr(pos,len);
        }
        answer.push_back(mp[w]); // 색인 번호 push
        mp[msg.substr(pos,len+1)] = mp.size()+1;
        pos+=len;
    }
    return answer;
}