#include<bits/stdc++.h>
using namespace std;
bool visited[54];
bool convert(string &a, string &b)
{
    int count=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]!=b[i]) count++;
        if(count>1) return false;
    }
    return true;
}
int solution(string begin, string target, vector<string> words) {
    if(find(words.begin(),words.end(),target)==words.end()) return 0;
    queue<pair<string,int>> q;
    q.push({begin,0});
    while(q.size())
    {
        string cur=q.front().first;
        int cnt=q.front().second;
        q.pop();
        
        if(cur==target) return cnt;
        
        for(int i=0;i<words.size();i++)
        {
            if(!visited[i] && convert(cur,words[i]))
            {
                visited[i]=true;
                q.push({words[i],cnt+1});
            }
        }
    }
    return 0;
}
