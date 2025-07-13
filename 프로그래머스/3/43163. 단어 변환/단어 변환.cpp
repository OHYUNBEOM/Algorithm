#include<bits/stdc++.h>
using namespace std;
bool convert(string &a, string &b)
{
    int count=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]!=b[i]) count++;
        if(count>1) return false;
    }
    if(count==1) return true;
}
int solution(string begin, string target, vector<string> words) {
    if(find(words.begin(),words.end(),target)==words.end()) return 0; // words 단어 중 target이 없음
    queue<pair<string,int>> q; // 현재 단어, cnt
    vector<bool> visited(words.size(),0);
    
    q.push({begin,0});
    
    while(q.size()) // 탐색
    {
        string cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(cur==target) return cnt; 
        
        for(int i=0; i<words.size(); i++) // words 단어들과 비교
        {
            if(!visited[i] && convert(cur,words[i])) // 확인하지 않았고 변환이 가능하다면
            {
                visited[i]=true; // 방문 처리
                q.push({words[i],cnt+1}); // 갱신
            }
        }
    }
    return 0;
}