#include<bits/stdc++.h>
using namespace std;
int solution(vector<int> priorities, int location) {
    queue<int> q;
    vector<int> v;
    for(int i=0;i<priorities.size();i++)
    {
        q.push(i); // index만 순서대로 저장
    }
    while(q.size())
    {
        int n=q.front();q.pop();
        // 우선순위가 더 높은 프로세스가 있는 경우
        if(priorities[n]!=*max_element(priorities.begin(),priorities.end()))
        {
            q.push(n);
        }
        else // 우선순위가 가장 높은 경우
        {
            v.push_back(n); // v에 index 번호 삽입
            priorities[n]=0; // 프로세스 실행한 경우 0으로 변경
        }
    }
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==location) return i+1;
    }
}