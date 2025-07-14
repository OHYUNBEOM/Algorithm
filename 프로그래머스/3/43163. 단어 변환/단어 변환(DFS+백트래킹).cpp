#include<bits/stdc++.h>
using namespace std;
bool visited[54];
int ret = INT_MAX;
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
void dfs(string cur, string target, vector<string> words, int cnt)
{
    if(cur==target)
    {
        ret=min(ret,cnt);
    }
    for(int i=0;i<words.size();i++)
    {
        if(!visited[i] && convert(cur,words[i]))
        {
            visited[i]=true;
            dfs(words[i],target,words,cnt+1);
            visited[i]=false;
        }
    }
}
int solution(string begin, string target, vector<string> words) {
    if(find(words.begin(),words.end(),target)==words.end()) return 0;
    dfs(begin,target,words,0);
    
    if(ret==INT_MAX) return 0;
    else return ret;
}
