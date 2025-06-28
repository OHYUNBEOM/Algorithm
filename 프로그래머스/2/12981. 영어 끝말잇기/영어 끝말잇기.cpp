#include<bits/stdc++.h>
using namespace std;
vector<int> solution(int n, vector<string> words) { 
    map<string,int> mp;
    for(int i=0;i<words.size();i++)
    {
        string cur=words[i];
        mp[cur]++;
        if(mp[cur]>=2) // 중복 단어 검사
        {
            return {i%n+1,i/n+1};
        }
        
        if(i>0) // 끝말잇기 규칙 검사
        {
            if(words[i-1].back()!=words[i].front())
            {
                return {i%n+1,i/n+1};
            }
        }
    }
    return {0,0};
}