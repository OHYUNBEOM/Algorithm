#include<bits/stdc++.h>
using namespace std;
int solution(int cacheSize, vector<string> cities) {
    int ret=0;
    int n=cities.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<cities[i].size();j++)
        {
            cities[i][j]=tolower(cities[i][j]);
        }
    }
    list<string> lst; // cache를 담을 자료구조
    for(int i=0;i<n;i++)
    {
        auto it = find(lst.begin(),lst.end(),cities[i]); // cache에서 못찾으면 lst.end() 반환
        if(it!=lst.end()) // cache hit
        {
            lst.erase(it);
            lst.push_back(cities[i]);
            ret+=1;
        }
        else // cache miss
        {
            ret+=5;
            if(cacheSize>0)
            {
                if(lst.size()==cacheSize) // cache miss가 났고 cache가 꽉 찼다면
                {
                    lst.pop_front(); // 가장 오래된 cache 도시 삭제
                }
                lst.push_back(cities[i]); // 순서 중요, cache 다 찼으면 앞에 하나 비워주고 push_back
            }
        }
    }
    return ret;
}