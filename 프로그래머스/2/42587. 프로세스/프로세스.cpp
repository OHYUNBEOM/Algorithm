#include<bits/stdc++.h>
using namespace std;
int solution(vector<int> priorities, int location) {
    int n=priorities.size();
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++)
    {
        q.push({priorities[i],i}); //priorities[i] : 우선순위, i : index(location)
    }
    int ret=0;
    while(q.size())
    {
        auto cur=q.front(); q.pop();
        bool high=false;
        queue<pair<int,int>> temp=q; // 복사본으로 검사
        while(temp.size())
        {
            if(temp.front().first>cur.first)
            {
                high=true;
                break;
            }
            temp.pop();
        }
        if(high) // 우선순위가 더 높은놈이 있는 경우
        {
            q.push(cur); // 뒤로 보냄
        }
        else // 우선순위가 더 높은놈이 없는 경우
        {
            ret++;
            if(cur.second==location)
            {
                return ret;
            }
        }
    }
    return ret;
}