#include<bits/stdc++.h>
using namespace std;
const char vowel[5] = {'A','E','I','O','U'};
int ret,cnt;
void dfs(string cur,string target)
{
    if(cur==target)
    {
        ret=cnt;
        return;
    }
    
    if(cur.length()==5) return;
    
    for(int i=0;i<5;i++)
    {
        cnt++;
        dfs(cur+vowel[i],target);
        //if(ret) return;
    }
}
int solution(string word) {
    dfs("",word);
    return ret;
}