#include<bits/stdc++.h>
using namespace std;
int solution(int cacheSize, vector<string> cities) {
    int ret=0; // 실행 시간
    int n=cities.size(); // 도시들
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<cities[i].size();j++)
        {
            cities[i][j]=tolower(cities[i][j]);
        }
    }
    list<string> lst;
    for(int i=0;i<n;i++)
    {
        auto it=find(lst.begin(),lst.end(),cities[i]);
        if(it!=lst.end()) //cache hit
        {
            ret+=1;
            lst.erase(it);
            lst.push_back(cities[i]);
        }
        else // cache miss
        {
            ret+=5;
            if(cacheSize>0)
            {
                if(lst.size()==cacheSize)
                {
                    lst.pop_front();
                }
                lst.push_back(cities[i]);
            }
        }
    }
    return ret;
}