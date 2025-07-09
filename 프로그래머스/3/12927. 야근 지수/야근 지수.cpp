#include<bits/stdc++.h>
using namespace std;
long long solution(int n, vector<int> works) {
    long long answer = 0;
    int check=0;
    for(int i=0;i<works.size();i++)
    {
        check+=works[i];
    }
    if(check<=n) return 0;
    sort(works.begin(),works.end());
    reverse(works.begin(),works.end());
    while(n>0)
    {
        //sort(works.begin(),works.end());
        //reverse(works.begin(),works.end());
        
        int mx=works[0];
        int cnt=count(works.begin(),works.end(),works[0]);
        
        if(n>=cnt)
        {
            for(int i=0;i<works.size();i++)
            {
                if(works[i]==mx)
                {
                    works[i]--;
                }
            }
            n-=cnt;
        }
        else // 최댓값이 일할 수 있는 시간보다 많다
        {
            for(int i=0;i<works.size() && n>0;i++)
            {
                if(works[i]==mx)
                {
                    works[i]--;
                    n--;
                }
            }
            break;
        }
    }
    for(int i=0;i<works.size();i++)
    {
        answer+=works[i]*works[i];
    }
    return answer;
}